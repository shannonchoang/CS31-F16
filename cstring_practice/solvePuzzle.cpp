#include <iostream>
#include <string>
using namespace std; 

void solvePuzzle(char encodedMsg[] ,char decodedMsg[])
{
	int lenEncoded = strlen(encodedMsg);
	int MsgIndx = 0; 
	//for length of string 
	for (int i = 0; i < lenEncoded; i+=2)
	{
		//place 1st, 3rd, 5th, 
		decodedMsg[MsgIndx] = encodedMsg[i];
		MsgIndx++;
	}

} 

int main()
{
char encodedMsg[] = "BAAANPALNEA";
char decodedMsg[100];
solvePuzzle(encodedMsg,decodedMsg);
cout << "The decoded message is: " << decodedMsg << endl;
return 0;
}