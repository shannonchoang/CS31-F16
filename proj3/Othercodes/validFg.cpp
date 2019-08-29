
#include <iostream> 
#include <string> 
#include <cctype> 
using namespace std; 


string cmdstr = "f"; 
bool validFg (string& cmdstr) 
{
	// when you are checking the next character
	// make sure it exists first or you will get error

	// CONSIDER THIS CASE:
	// given, cmdstr = "f", pos = 0 -> return false
	// this better not crash
	if (isprint(cmdstr[pos + 1 ]))
	{
		return true; 
	}
	else 
	{
		return false; 
	}
}

int main () 
{
	if (validFg(cmdstr))
	{
		cout << "if validFg ran" << endl; 
	}
	else
	{
		cout << "invalid Fg ran" << endl; 
	}

}