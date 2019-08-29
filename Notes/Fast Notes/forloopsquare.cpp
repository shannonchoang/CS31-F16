
#include <iostream>
#include <cctype>
using namespace std; 

//want loop that adds a new # each time 
//want loop that prints a space numberentered-1


int i;
int j; 
int h; 

int numEntered;

int main() 
{
	cin >> numEntered;
	for (int h = 0; h < numEntered; h++)
	{
			for (int i = 0; i < numEntered; i++)
			{
				for (int j = i; j + 1 < numEntered; j++)
				{
				cout << " ";
				}
		
			cout << "#";
			
			}
	cout << endl;
	}	
} 


/* 
numEntered=3
0 < 3 
	  "  "


*/ 
