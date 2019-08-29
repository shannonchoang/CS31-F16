#include <iostream>
#include <string>
#include <assert.h>
using namespace std; 

//TODO: what if both string sizes are equal to zero
//TODO: what is both strings sizes are equal and 
//the strings are equal all the way 
int locateDifference(const string a1[], int n1, const string a2[], int n2)
{
	int curridx;
	//elements number cannot be negative 
	if (n1 < 0 || n2 < 0 || n1 == 0 || n2 == 0)
	{
		return -1; 
	}
	for (curridx = 0; curridx < n1 && curridx < n2; curridx++)
	{
		if (a1[curridx] != a2[curridx])
		{
			return curridx; 
		}
	}
	//should one run out and equal up to there, return smaller of n1/n2
	return curridx; 
}

int main ()
{
	string cast[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	string roles[4] = { "malory", "lana", "krieger", "ray" };
	//same up to sterling/krieger
		assert(locateDifference(cast, 5, roles, 4) == 2);  
	//one runs out, return smaller 
		assert(locateDifference(cast, 2, roles, 1) == 1); 
	//elements number cannot be negative 
		assert(locateDifference(cast, -5, roles, 1) == -1);
	//one string size equal to 0 
		assert(locateDifference(cast, 0, roles, 4) == -1);
	//both string size equal to 0 
		assert(locateDifference(cast, 0, roles, 0) == -1);
	cerr << "passed locateDifference tests" << endl;
}
