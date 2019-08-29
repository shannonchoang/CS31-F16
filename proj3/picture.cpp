#include "graphlib.h"
#include <iostream>
#include <assert.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////
/////////////////////////BEGIN PROJECT 3 CODE///////////////////////////////
////////////////////////////////////////////////////////////////////////////

#include <cctype>

bool plotLine(int r, int c, int dir, int distance, char plotChar, int fgbg)
{
	//checks if dir is HORIZ or VERT 
	// dir == 0, HORIZ, dir == 1, VERT
	if (!(dir == 0 || dir == 1)) 
	{
		return false;
	}
	
 
	//checks fgbg parameter is FG or BG
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
	if ((r < 0) || (r > 20))
	{
		//cerr << "Error, invalid row value" << endl; // TODO: print error messages using cerr or cout? 
		return false;
	} 
	if ((c < 0) || (c > 30))
	{
		//cerr << "Error, invalid column value" << endl; ok to print to cerr?
		return false;
	}
	
	
	// TODO: figure out when distance is bad
		// right or down
		if (distance >= 0)
		{
			// right
			if (dir == 0) // horizontal
			{
				for (int currDist = 0; currDist <= distance; currDist++)
				{

					int currCol = c + currDist;

					//if FG or available space setChar
					if (fgbg == 1 || (getChar(r, currCol) == ' '))
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
					int currRow = r + currDist;

					// if FG or available space setChar
					if (fgbg == 1 || (getChar(currRow, c) == ' '))
					{
						setChar(currRow, c, plotChar);
					}
					// r++; 					
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
					cout << fgbg << endl;
					cout << getChar (r,c) << endl;
					if (fgbg == 1 || (getChar(currRow,c) == ' '))
					{
						setChar (currRow, c, plotChar);
					}	
					else 
					{

						cerr << "I didn't print :(" << endl;
					}
				}
			}
		}
		
	return true; 

}


////////////////////////////////////////////////////////////////////////////
////////////////////////// END PROJECT 3 CODE //////////////////////////////
////////////////////////////////////////////////////////////////////////////

int main()
{
    clearGrid();
    
  	//(int r, int c, int dir, int distance, char plotChar, int fgbg)
    //dir = 1 VERT ; dir = 0 HORIZ 
    //DIST pos - rightward or downard from (r,c)
    //DIST neg - leftward or upward from (r,c)


    //prints rightward from 5, 1 by 6
    plotLine (5, 1, 0, 6, '1', 1);
    assert (getChar(5,1) == '1');
    assert (getChar (5, 11) == '1');
    //prints downward from 5,1 by 6, first char shouldn't print 
    plotLine (5, 1, 1, 7, '2', 0);
    assert ((getChar(5,1))!= '2');



    //prints leftward from 13, 17 by 5 
    plotLine (13, 17, 0, -5, '@', 0);
    assert ((getChar (13, 12)) == '@');
    //prints upward from 14, 20 by 11; a char should overlap 
    plotLine (14, 17, 1, -11, '#', 1); 
    assert ((getChar (14, 17)) != '@');
    assert ( (getChar (3, 17)) == '#'); 

    draw();
}