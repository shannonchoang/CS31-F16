#include <iostream>
#include <string>
#include <cassert>
using namespace std; 


//returns the number of strings in array equal to target
//TODO: what if number of elements is equal to zero? 
int enumerate(const string a[], int n, string target)
{ 
	//if number of elements is 0, return -1 
	if (n < 0) 
	{
		return -1; 
	}
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
//TODO, if n=0, should return false? does the function handle that already? 
//return position of a string in array equal to target 
int locate(const string a[], int n, string target)
{
	//if a[pos] == string return position 
	// if not, go to next character in string 
	// if n > 0, don't go into loop, just return -1 
	for (int pos = 0; pos < n && n > 0; pos++)
	{
		if (a[pos] == target)
		{
			return pos; 
		}
	}
	return - 1; 
}
//TODO: if n=0, should return false?
//find first position of consec string and last pos of consec string 
bool locateSequence(const string a[], int n, string target, int& begin, int& end)
{
	if (n <= 0)
	{
		return false; 
	}
	//through the loop 
	for (int currPos = 0; currPos < n; currPos++)
	{
		//if find target set beginning = current 
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
//returns position of string in array such that it is <=
//every string in array
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
//copy all elements after pos one element to the left 
int moveToEnd(string a[], int n, int pos)
{
	//if elements number negative or position out of scope 
	if (n <= 0 || pos > n)
	{
		return -1; 
	}

	//save these values to use at the end
	const int originalPos = pos; 
	const string temp = a[originalPos]; 		
	for (int i = pos; i+1 < n; i++)
	{ 
		cerr << "replace " << a[i] << "with " << a[i+1] << endl;
		a[i] = a[i+1]; //sets current equal to character after it 
	}
 	a[n - 1] = temp;
	return originalPos;  
}

//move string in pos to first pos in the array 
//return original position of item moved
//we want to shift everything before the original to the left 
int moveToBeginning(string a[], int n, int pos)
{
	//if elements number negative or position out of scope 
	if (n <= 0 || pos > n)
	{
		return -1;
	}

	const int originalPos = pos; 
	const string temp = a[originalPos];
	for (int i = pos; i >= 0; i--)
	{
		a[i] = a[i - 1]; //sets current equal to character before it 
	}
	a[0] = temp; 
	return originalPos; 
}
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
//deletes duplicates 
//return number of retained items
int eliminateDups(string a[], int n)
{
	// end of the array
	int end = n;
	int numRetained = 0; 
	int i; 
	//number of elements cannot be negative 
	if (n < 0)
	{
		return -1;
	}
	// for every string
	for (int idx = 0; idx < end;) 
	{
		//if it's in bounds and it's a duplicate 
		if(idx + 1 < end && a[idx] == a[idx + 1]) 
		{
			// remove an element by copying over everything
			for (i = idx; i < end && (i + 1) < end; i++)
			{ 
				a[i] = a[i + 1]; 
			}
			end--;
		} 
		else
		{
			idx++; 
			numRetained++;
		}
	}	
	return numRetained;
}

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

int makeMerger(const string a1[], int n1, const string a2[],
int n2, string result[], int max)
{
	int idx1 = 0; 
	int idx2 = 0; 

	//if two arrays combined more than max result size 
	if (max < n1 + n2) 
	{
		cerr << "max less than needed capacity" << endl;
		return -1; 
	}
	//check if both are non decreasing 
	// for(int apos = 0; a1[apos] < n1; apos++)

	for (int idx3 = 0; idx3 < n1+n2; idx3++)
	{
		//are the arrays in nondecreasing order 
		int next = idx3 + 1; 
		if (((a1[idx3] > a1[next]) && next < n1) || ((a2[idx3] > a2[next]) && next < n2))
		{
			return -1; 
		}
			//if a1 > a2, set position in result array = a2
		if (idx1 < n1 && idx2 < n2 && a1[idx1] >= a2[idx2])
		{
			result[idx3] = a2[idx2];
			idx2++; 
		}
		//if a1 < a2, set next position in result array = a1 
		else if (idx1 < n1 && idx2 < n2 && a2[idx2] > a1[idx1])
		{
			result[idx3] = a1[idx1];
			idx1++;
		} 
		//we ran out of elements for n1
		else if (idx1 == n1)
		{
			result[idx3] = a2[idx2];
			idx2++; 

		}
		//ran out for n2
		else if (idx2 == n2)
		{
			result[idx3] = a1[idx1];
			idx1++; 
		}
	
	}
	//size of new array
	return n1+n2;  
}
int divide(string a[], int n, string divider)
{

	//if negative elements, bad parameter
	if (n < 0)
	{
		return -1; 
	}

	int count = 0; 
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) {
			cerr << a[j] << " ";
		}

		if (a[i] < divider) 
		{
			cerr << " -- moving " << a[i] << " to the end";
			moveToBeginning(a, n, i);
			count++;
		}
		cerr << endl;
		// string REMOVEME;
		// cin >> REMOVEME;
	}
	return count; 
}

int main ()
{
	string h[7] = { "malory", "sterling", "lana", "cheryl", "", "cyril", "lana" };
	    assert(enumerate(h, 7, "lana") == 2);
	    assert(enumerate(h, 7, "") == 1);
	    assert(enumerate(h, 7, "krieger") == 0);
	    assert(enumerate(h, 0, "lana") == 0);
	    assert(locate(h, 7, "lana") == 2);
	    assert(locate(h, 2, "lana") == -1);
	    int bg;
	    int en;
	    assert(locateSequence(h, 7, "cheryl", bg, en) && bg == 3 && en == 3);

	    string g[4] = { "malory", "sterling", "cheryl", "cyril" };
	    assert(locationOfMin(g, 4) == 2);
	    assert(locateDifference(h, 4, g, 4) == 2);
	    assert(subsequence(h, 7, g, 4));
	    assert(moveToEnd(g, 4, 1) == 1 && g[1] == "cheryl" && g[3] == "sterling");
	
	    string f[4] = { "cyril", "cheryl", "sterling", "lana" };
	    assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "sterling" && f[2] == "cheryl");
	
	    string e[5] = { "cyril", "cyril", "cyril", "sterling", "sterling" };
	    assert(eliminateDups(e, 5) == 2 && e[1] == "sterling");
	
	    string x[4] = { "cyril", "krieger", "krieger", "pam" };
	    string y[4] = { "cheryl", "krieger", "lana", "sterling" };
	    string z[10];
	    assert(makeMerger(x, 4, y, 4, z, 10) == 8 && z[5] == "lana");
	
	    assert(divide(h, 7, "lana") == 3);
	
	    cout << "All tests succeeded" << endl;
}