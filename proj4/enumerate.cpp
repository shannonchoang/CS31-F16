#include <iostream>
#include <string>
#include <assert.h>
using namespace std; 


//returns the number of strings in array equal to target 
int enumerate(const string a[], int n, string target)
{ 
		//number of elements equal to target
		int targetElements = 0; 

		//for all elements in array 
		for (int pos = 0; pos < n; pos++ )
		{
			if (a[pos] == target)
			{
				targetElements++;
			}
		}
	return targetElements;
}

//return position of a string in array equal to target 
int locate(const string a[], int n, string target)
{
	//if a[pos] == string return position 
	// if not, go to next character in string 
	for (int pos = 0; pos < n; pos++)
	{
		if (a[pos] == target)
		{
			return pos; 
		}
	}
	return - 1; 
}
//find first position of consec string and last pos of consec string 
bool locateSequence(const string a[], int n, string target, int& begin, int& end)
{
	//run through the array
	if (n < 0)
	{
		return false; 
	}

	for (int currPos = 0; currPos < n; currPos++)
	{
		if (a[currPos] == target)
		{
			begin = currPos; 
			end = begin; 
			for (int nextString = begin + 1 ; nextString <= n && a[nextString] == target; nextString++)
			{
				end = nextString;
			}
			return true; 
		}	
	}
	
	return false; 
}

//return location of alphabetically first string 
int locationOfMin(const string a[], int n)
{
	int currMin = 0; 
	for (int currPos = 0; currPos < n; currPos++)
	{
		if (a[currPos] <= a[currMin])
		{
			currMin = currPos; 
		}
	} 
return currMin; 
}

// string people[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
// int j = moveToEnd(people, 5, 1);  // returns 1
//string people now contains same thing with lana at the end 

//move item at position all the way to the end 
int moveToEnd(string a[], int n, int pos)
{
	for (int i = pos; i < n; i++)
	{ 
		a[i - 1] = a[i];
	}
return pos;  
}


	





int main() 
{
	//test cases for enumerate
	string animals[4] = {"dog", "cat", "dog", "dog"};
	string dog = "dog"; 
	string cat = "cat"; 
	string bird = "bird"; 
	assert (enumerate (animals, 4, dog) == 3); 
	assert (enumerate (animals, 4, cat) == 1); 
	assert (enumerate (animals, 4, bird) == 0);
	cout << "enumerate test cases passed" << endl; 

	//test cases for locate
	assert (locate(animals, 4, dog) == 0);
	assert (locate (animals, 4, cat) == 1); 
	cout << "locate test cases passed" <<endl; 

	//test cases for locate sequence 
	string a[9] = {
	"lana", "cyril", "malory", "malory", "sterling", 
	"sterling", "sterling", "malory", "malory"};
	string t2 = "sterling"; 
	int b;
	int e;
	assert(locateSequence(a, 9, t2, b, e)); 
	assert(b == 4 && e == 6); 
	string t3 = "margaret"; 
	assert(!locateSequence(a, 9, t3, b, e));
	cout << "locateSequence test cases passed" << endl;

	//test cases for locationOfMin
	string fruits[3] = {"kiwis", "clementines", "cantalope"};
	assert (locationOfMin(fruits, 3) == 2);  
	string names[6] = 
	{"zenon", "clarrice", "anna", "zack",
	 "bernice", "alice"};
	assert (locationOfMin(names, 6) == 5); 
	string places[6] = 
	{"costa rica", "zealand", "california", "massachusetts",
	 "appalachians", "antartica" };
	 //only looking at first two elements
	assert(locationOfMin(places, 2) == 0);
	//first 3 elements 
	assert(locationOfMin(places, 3) == 2); 
	assert(locationOfMin(places, 6) == 5);
	cerr << "passed locationOfMin test cases" << endl;
}

	



