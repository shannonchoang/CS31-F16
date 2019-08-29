#include <iostream>
#include <string>
using namespace std;

int updatePoints(int pos)
{
 if( pos == 3 ) return 1;
 if( pos == 1 ) return -1;
 if( pos == 5 ) return 2;
 if( pos == 2 ) return -2;
 	return 0;

}
int executeCommands(string cmdStr, int pos, int points)
{
	int i; 
	 //if initial pos gets points, update
	points += updatePoints(pos); 
 	for (int i = 0; i < cmdStr.size(); i++) //loops through commandstr
 	{
 		switch(cmdStr[i])
 		{
 			case 'L':
 			pos -=1; 
 			points += updatePoints(pos);
 			break;

 			case 'R':
 			pos +=1; 
 			points += updatePoints(pos); 
 			break;

 			case 'U':
 			points += updatePoints(pos);
 			break; 

 			case 'D':
 			points += updatePoints(pos);
 			break; 

 			default: //invalid Cmd 
 			return -1; 
 		}
 	}
 	return points; //after reading entire cmdStr
 }
int main()
{
 string command1 = "LULDR";
 string command2 = "LRDULRDUXX";
 string command3 = "UUDDLLRRBA";
 string command4 = "DDURDDUR";
 cout << executeCommands(command1, 0 , 0) << endl;
 cout << executeCommands(command2, 1 , 1) << endl;
 cout << executeCommands(command3, 2 , 2) << endl;
 cout << executeCommands(command4, 3 , 3) << endl;
} 