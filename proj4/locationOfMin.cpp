#include <iostream>
#include <string>
#include <assert.h>
using namespace std; 

int locationOfMin(const string a[], int n)
{
	//array has no elements or negative elements
	//TODO: check if this is necessary under the spec
	if (n <= 0)
	{
		return -1; 
	}
	int currMin = 0; 
	for (int currPos = 0; currPos < n; currPos++)
	{
		if (a[currPos] < a[currMin])
		{
			currMin = currPos; 
		}
	} 
return currMin; 
}
	
int main ()
{
	// //locationOfMin test cases 
	// string fruits[3] = {"kiwis", "clementines", "cantalope"};
	// assert (locationOfMin(fruits, 3) == 2);  
	
	// string places[6] = 
	// {"costa rica", "zealand", "california", "massachusetts",
	//  "appalachians", "antartica" };
	//  //costrica vs zealand
	// assert(locationOfMin(places, 2) == 0);
	// //first 3 elements 
	// assert(locationOfMin(places, 3) == 2); 
	// assert(locationOfMin(places, 6) == 5);

	// //two elements that are min 
	// string stds[4] = {"herpes", "chlamydia", "crabs", "chlamydia"};
	// assert(locationOfMin(stds, 4) == 1);

	//all elements are the same and are min 
	// string feelings[2] = {"sad", "sad"};
	// assert(locationOfMin(feelings,2) == 0);

	cerr << "passed locationOfMin tests" << endl;

	//TODO: QUESTION, if there is more than one string to deal with, my results don't come out
	//correctly 
	//i.e. I can't do string fruits test and string places test at the same time 
}