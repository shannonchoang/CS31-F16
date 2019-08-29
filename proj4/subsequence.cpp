#include <iostream> 
#include <string>
#include <assert.h>
using namespace std;  


//TODO: handling an empty big array
//TODO: what if both arrays are empty
//if all n2 elements appear in a1, not in necessarily consecutively
bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	int bIndex;
	int sIndex = 0;

	for (bIndex = 0; bIndex < n1; bIndex++)
	{
		if (n2 == 0)
		{
			return true;
		}
		if (a1[bIndex] == a2[sIndex] && sIndex < n2)
		{
			sIndex++; 
		}
	}
    //all elements in a2 appear in a
	if (sIndex == n2)
	{
		return true; 
	}
	// if the complete subsequence wasn't found
	return false; 
}

int main ()
{
	//subsequence test cases 
	string big1[10] = {"malory", "lana", "sterling", "cheryl", "cyril", "sterling"};
	string little1[10] = {"lana", "cheryl", "cyril"}; 
	string little2[10] = { "sterling", "lana" };
	//true case
		assert(subsequence(big1, 6, little1, 3) == true);
	//false case 
	 	assert(subsequence(big1, 6, little2, 2) == false);
	//0 elements big array
	 	assert(subsequence(big1, 0, little2, 3) == false);
	//0 elements in small array, empty subsequence 
	 	assert(subsequence(big1, 6, little2, 0) == true);
	//negative elements 
	 	assert(subsequence(big1, -6, little1, 3) == false);
	 	assert(subsequence(big1, 6, little1, -3) == false);
	cerr << "passed subsequence test cases" << endl;
}
	
