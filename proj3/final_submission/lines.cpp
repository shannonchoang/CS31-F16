#include <iostream> 
#include "graphlib.h"
#include <string> 
#include <cctype>
#include <assert.h>
using namespace std; 

//checks if last row or column is valid 
bool validDistance (int currRow, int currCol, int dir, int distance)
{
	if (distance >= 0) 
	{
		//if moving rightward, we don't want last column beyond 30
		if (dir == 0 && (currCol + distance) <= 30)
		{
			return true; 
		}
		//if moving down vertically, we don't want last row beyond 20 
		else if (dir == 1 && (currRow + distance) <= 20)
		{
			return true; 
		}
		else 
		{
			return false; 
		}
	}
	else if (distance < 0) 
	{

		//moving left, we want to move beyond column 1 
		if (dir == 0 && !((currCol + distance) < 1))
		{
			return true; 
		}
		//moving up, we don't want to move beyond row 1 
		else if (dir == 1 && !((currRow + distance) < 1))
		{
			return true; 
		}
		else 
		{
			return false; 
		}
	}

	return true;
}

//checks if all parameters are valid, and if so attempts to plot them 
//according to parameters 
bool plotLine(int r, int c, int dir, int distance, char plotChar, int fgbg)
{
	//checking if parameters are valid: 
	//checks if dir is HORIZ or VERT 
	// dir == 0, HORIZ, dir == 1, VERT
	if (!(dir == 0 || dir == 1)) 
	{
		return false;
	}
	//checks if gbg parameter is FG or BG
	// FG = 1; BG = 0; 
	if (!(fgbg == 1 || fgbg == 0))
	{
		return false;
	}
	//checks if plotChar is "printable"
	if (!(isprint(plotChar)))
	{
		return false;
	}
	// checks if rows and columns are valid values
	if ((r < 1) || (r > 20))
	{
		return false;
	} 
	if ((c < 1) || (c > 30))
	{
		return false;
	}  
	//checks if command plots within the grid 
	if (!(validDistance (r, c, dir, distance)))
	{
		return false; 
	}

	// line is going right or down
	if (distance >= 0)
	{
		// right
		if (dir == 0) // horizontal
		{
			for (int currDist = 0; currDist <= distance; currDist++)
			{
				//currCol = original column + distance traveled
				int currCol = c + currDist;
		
				//if FG or available space setChar
				if ((fgbg == 1 || (getChar(r, currCol) == ' ')))
				{
					setChar(r, currCol, plotChar);
				}
				
			}
				
		}
		// down
		else if (dir == 1) // vertical
		{
			for (int currDist = 0; currDist <= distance; currDist++)
			{
				//currRow = original row + distance traveled 
				int currRow = r + currDist;

				// if FG or available space setChar
				if (fgbg == 1 || (getChar(currRow, c) == ' '))
				{
					setChar(currRow, c, plotChar);
				}					
			}
		}
	}
	// left or up
	else // if (distance < 0)
	{
		// left
		if (dir == 0) // if HORIZ
		{
			for (int currDist = 0; currDist >= distance; currDist--)
			{
				int currCol = c + currDist; 

				//if FG or available space setChar 
				if (fgbg == 1 || (getChar(r,currCol) == ' '))
				{
					setChar (r, currCol, plotChar);
				}
			}
		}
		// up
		else if (dir == 1) // if VERT 
		{
			for (int currDist= 0; currDist >= distance; currDist--) 
			{
				int currRow = r + currDist; 

				if (fgbg == 1 || (getChar(currRow,c) == ' '))
				{
					setChar (currRow, c, plotChar);
				}	
			}
		}
	}
	//if all the parameters passed and if the line
	//was successfully plotted 	
	return true; 
}


// returns true if command starting at cmdstr[pos] 
// is a valid FgBg cmd, meaning there is a printable character after
// only changes pos if there was a bad pos
bool validFgBg (string& cmdstr, int& pos) 
{
	// ERRORS IN 2nd CHAR: 
	// either theres no second character in cmd
	// or theres non printable character in second char
	if (pos + 1 >= cmdstr.size() || !isprint(cmdstr[pos + 1])) 
	{
		// increment pos for badPos in execute commands
		pos++;
		return false;
	}
	return true;
}

// returns true if command starting at cmdstr[pos]
// is a valid plot command
// Note: only changes pos if there was a bad pos
bool validPlotCmd (string& cmdstr, int& pos, int& dist, int& numChar) 
{ 
	int digitCount = 0;
	bool isNeg = false;

	// if string has another character and it is a '-'
	if (pos + 1 < cmdstr.size() && cmdstr[pos + 1] == '-') 
	{ 
		isNeg = true;
		// increment pos so it is now just before potential digits
		pos++;
	}

	// assuming pos points right before digits
	// if a digit exists add one to digitCount
	if (pos + 1 < cmdstr.size () && isdigit(cmdstr[pos + 1]))
	{
		digitCount++;
	} 
	// else return false because inValid PlotCmd
	else // doesnt exist OR is not a digit
	{
		pos++; 
		return false;
	}

	// assuming pos points right before digits
	if (pos + 2 < cmdstr.size () && isdigit(cmdstr[pos + 2]))
	{
		digitCount++;
	} 

	if (digitCount == 1)
	{
		//setting distance 
		dist = cmdstr[pos + 1] - '0';
	}
	else // digitCount == 2 
	{
		dist = ((cmdstr[pos + 1] - '0') * 10) + (cmdstr[pos+ 2] - '0'); 
	}

	// set the number of chars that this command spans
	numChar = digitCount + 1;

	//if number was neg, previously set isNeg = true; 
	if (isNeg) 
	{
		dist *= -1;
		numChar++;
		pos--;
	}
	return true; 
}

//executes commands in string 
int executeCommands(string commandString, char& plotChar, int& mode, int& badPos) 
{
	//default row and column positions specified by spec 
	int currRow = 1;
	int currCol = 1;
	int dist = 0;
	int numChar = 0;

	// for every character in the cmdstring
	for (int pos = 0; pos < commandString.size();) {
		char currChar = commandString[pos];

		switch (currChar) {
			case 'f':
			case 'F':
				// invalid fg syntax
				if(!validFgBg(commandString, pos)) 
				{
					badPos = pos;
					return 1;
				}
				//if valid, set mode = 1 and set plotChar = next character
				mode = 1; 
				plotChar = commandString[pos + 1];
				//command should be max of 2 characters 
				pos += 2;

				break;
			case 'b':
			case 'B':
				// invalid bg syntaxx
				if(!validFgBg(commandString, pos)) 
				{
					badPos = pos;
					return 1;
				}
				//if valid, set mode = 0(spec), set plotChar = next char
				mode = 0; 
				plotChar = commandString[pos + 1];
				//command should be max 2 chars 
				pos += 2; 

				break;
			//clears the grid
			case 'c':
			case 'C':
				clearGrid(); 
				//one character command
				pos++;
				currRow = 1; 
				currCol = 1; 
				plotChar = '*';
				break;
			case 'h':
			case 'H':	
			
				// invalid horizontal syntax
				// if invalid PlotCmd or Distance, 
				if(!validPlotCmd(commandString, pos, dist, numChar)) 
				{
					badPos = pos;
					return 1;
				}
				// TODO: plot a horizontal line using current modes
				// Note - if line would plot off the edge, return 2
				// Note - dont forget to set the currRow/Col after
				if (!validDistance(currRow, currCol, 0, dist))
				{
					badPos = pos; 
					return 2; 
				}
				plotLine(currRow, currCol, 0, dist,plotChar, mode);
				pos += numChar;
				currCol += dist;
				break;
			case 'v':
			case 'V':
				
				// invalid vertical syntax
				if(!validPlotCmd(commandString, pos, dist, numChar)) 
				{
					badPos = pos; 
					return 1;
				}
				// TODO: plot a vertical line using current modes
				// Note - if line would plot off the edge, return 2
				// Note - dont forget to set the currRow/currCol after
				if (!validDistance(currRow, currCol, 1, dist))
				{
					badPos = pos; 
					return 2; 
				}
				plotLine (currRow, currCol, 1, dist, plotChar, mode);
				pos += numChar;
				currRow += dist;
				break;
			default:
				// if we ever get here the syntax is wrong
				badPos = pos; 
				return 1;
		}
	}

	// syntax was correct and we can plot fine
	return 0;
}

const int HORIZ = 0;
const int VERT = 1;

const int BG = 0;
const int FG = 1;

// int main()
// {
// 	clearGrid();
    
//   	//(int r, int c, int dir, int distance, char plotChar, int fgbg)
//     //dir = 1 VERT ; dir = 0 HORIZ 
//     //DIST pos - rightward or downard from (r,c)
//     //DIST neg - leftward or upward from (r,c)
  
//     //POS DIST HORIZ: 
//     //prints rightward from 5, 1 by 6
//     assert(plotLine (5, 1, 0, 6, '1', 1));
    
//     // EDGE CASE: plotting just up to the edge and past
//     assert(plotLine (1, 1, 0, 29, '1', 1));
//     assert(!plotLine (1, 1, 0, 30, '1', 1));

//     //POS DIST VERT; FG/BG test 
//     //prints downward from 5,1 by 6, 1st char shouldn't print 
//     assert(plotLine (5, 1, 1, 6, '2', 0));

//     //NEG DIST HORIZ: 
//     //prints leftward from 17 by 5 
//     assert(plotLine (13, 17, 0, -5, '@', 0));
//     //prints upward from 14, 20 by 11; a char should overlap 
//     assert(plotLine (14, 17, 1, -11, '#', 1));

//     //DIST 0 a single ^ in background 
//     assert(plotLine (13, 9, 1, 0, '^', 0));  

//     //invalid parameters -- these should not print/do anything!
//     //bottom right corner: right and down
//   	assert(!plotLine(20, 30, 0, 1, '!', 1)); //this
//     assert (!plotLine (20, 30, 1, 1, '!', 1));
//     //bottom left corner left and down 
//    	assert (!plotLine (20, 1, 0, -1, '!', 1));
//     assert (!plotLine (20, 1, 1, 1, '!', 1));
//     //top left: left and up 
//     assert (!plotLine (1, 1, 0, -1, '!', 1)); 
//     plotLine (1, 1, 1, -1, '1', 1);
//     //top right: right and up 
//     assert (!plotLine (1, 30, 0, 1, '!', 1)); 
//     assert (!plotLine (1, 30, 1, -1, '!', 1));

//     //checks if chars are printed in the right places 
//     //first char FG is corr 
//     assert (getChar(5, 1) == '1');
//     //last char is corr
//     assert (getChar (5, 7) == '1');

//     //last char is corr 
//     assert (getChar (11, 1) == '2');
//     assert (getChar (10, 1) == '2');

//     //last char was correct 
// 	assert ((getChar (13, 12)) == '@');

// 	//should not print @ at position because BG 
//     assert ((getChar (13, 17)) != '@');

//     //first char printed 
//     assert ((getChar (3, 17)) == '#'); 
//     assert ((getChar (13, 9)) == '^');

//     //invalid parameter cases
//     cerr << "passed all plotline test cases" << endl;	
//     // draw ();

//     //valid distance 
//     //Top left corner 
// 	//HORIZ moving left out of bounds 
// 	assert (!(validDistance(1, 1, 0, -1))); 
// 	//VERT moving up out of bounds 
// 	assert(!(validDistance(1, 1, 1, -1))); 

// 	//Top right corner 
// 	//HORIZ moving right out of bounds 
// 	assert (!(validDistance (1, 30, 0, 1)));
// 	//VERT moving up out of bounds 
// 	assert (!(validDistance(1, 30, 1, -1)));

// 	//Bottom left 
// 	//HORIZ moving left out of bounds
// 	assert (!(validDistance (20, 1, 0, -1)));
// 	//VERT moving down out ofbounds 
// 	assert (!(validDistance (20, 1, 1, 1)));

// 	//Bottom right
// 	//HORIZ moving right out of bounds 
// 	assert (!(validDistance(20, 30, 0, 1)));
// 	assert (!(validDistance (20, 30, 1, 1)));   
	
// 	//Valid FgBg tests 
// 	string a = "f1";
// 	string b = "Fe";
// 	string c = "f";
// 	string d = "fë";
// 	int badPos = 0;
// 	assert (validFgBg(a, badPos));
// 	badPos = 0;
// 	assert (validFgBg (b, badPos));
// 	badPos = 0;
// 	assert (!validFgBg(c, badPos) && badPos == 1);
// 	badPos = 0;
// 	assert (!validFgBg(d, badPos) && badPos == 1);
// 	string e = "b^";
// 	string f = "B9";
// 	string g = "b"; 
// 	string h = "bé";
// 	badPos = 0;
// 	assert (validFgBg (e, badPos));
// 	badPos = 0;
// 	assert (validFgBg (f, badPos));
// 	badPos = 0;
// 	assert ((!validFgBg (g, badPos) && badPos == 1));
// 	badPos = 0;
// 	assert ((!validFgBg (h, badPos) && badPos == 1));


// 	//string& cmdstr, int pos, int& dist, int& numChar
//     //valid PlotCmd tests 
//     int dist;
// 	int numChar;
//     string s = "h1";
//     string t = "Hu";
//     badPos = 0;
//     assert (validPlotCmd(s,badPos, dist, numChar) && dist == 1);
//    	badPos = 0;
//     assert (!validPlotCmd(t,badPos, dist, numChar) && badPos == 1);
//     //invalid HORIZ line commands
//     string u = "h";
// 	badPos = 0;
//     assert (!validPlotCmd(u,badPos, dist, numChar) && badPos == 1);

// 	//validPlotCmd cases 
// 	string A = "h12V3H-1B@v-3";
// 	string H = "HAh-h-12H-5";
// 	string V = "VAv-v-12V-5";
	
// 	badPos = 0;
// 	assert (validPlotCmd(A, badPos, dist, numChar) && dist == 12);
// 	badPos = 3;
// 	assert (validPlotCmd(A, badPos, dist, numChar) && dist == 3);
// 	badPos = 5;
// 	assert (validPlotCmd(A, badPos, dist, numChar) && dist == -1);
// 	badPos = 10;
// 	assert (validPlotCmd(A, badPos, dist, numChar) && dist == -3);
// 	//B@ is not a validPlotCmd
// 	badPos = 8;
// 	assert ((!validPlotCmd(A, badPos, dist, numChar)));

// 	//invalid H commands 
// 	badPos = 0;
// 	assert (!validPlotCmd(H, badPos, dist, numChar) && badPos == 1);
// 	badPos = 2;
// 	assert (!validPlotCmd (H, badPos, dist, numChar) && badPos == 4);
// 	badPos = 4;
// 	assert (validPlotCmd (H, badPos, dist, numChar) && dist == -12);
// 	badPos = 8;
// 	assert (validPlotCmd (H, badPos, dist, numChar) && dist == -5);
// 	//invalid V commands 
// 	//becareful of moving this because it relies on prev test
// 	badPos = 1;
// 	assert (!validPlotCmd(V, badPos, dist, numChar) && badPos == 2);
// 	badPos = 2;
// 	assert (!validPlotCmd (V, badPos, dist, numChar) && badPos == 4);
// 	badPos = 4;
// 	assert (validPlotCmd (V, badPos, dist, numChar) && dist == -12);
// 	badPos = 8;
// 	assert (validPlotCmd (V, badPos, dist, numChar) && dist == -5);

// 	string B = "h12V3H-1B@v-3";
// 	string C = "v2b h12fHh1fih0";
// 	char plotChar = '*';
// 	int mode = 1;
// 	int badPos1;
// 	clearGrid();
// 	executeCommands(B, plotChar, mode, badPos1);
// 	executeCommands(C, plotChar, mode, badPos1);
// 	// draw();
// 	cerr << "all test cases passed!" << endl;
// 	return 0;
// }

int main()
{
    clearGrid();
    char currentChar = '*';
    int currentMode = FG;
    for (;;)
    {
        cout << "Enter a command string: ";
        string cmd;
        getline(cin, cmd);
        if (cmd == "")
            break;
        int position;
        int status = executeCommands(cmd, currentChar, currentMode, position);
        switch (status)
        {
            case 0:
                draw();
                break;
            case 1:
                cout << "Syntax error at position " << position+1 << endl;
                break;
            case 2:
                cout << "Cannot execute command at position " << position+1 << endl;
                break;
            default:
                // It should be impossible to get here.
                cerr << "executeCommands returned " << status << "!" << endl;
        }
    }
}


