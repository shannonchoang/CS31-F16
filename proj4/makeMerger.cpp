#include <iostream> 
#include <string> 
#include <assert.h>
using namespace std; 

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

	//the problem is the or equal operator doesn't necessarily apply to strings
	for (int idx3 = 0; idx3 < n1+n2; idx3++)
	{
		int next = idx3 + 1; 
		if (((a1[idx3] > a1[next]) && next < n1) || ((a2[idx3] > a2[next]) && next < n2))
		{
			return -1; 
		}
			//if a1 > a2, set position in result array = a2
		if (idx1 < n1 && idx2 < n2 && a1[idx1] >= a2[idx2])
		{
			result[idx3] = a2[idx2];
			cout << "increment idx2" << endl;
			idx2++; 
		}
		//if a1 < a2, set next position in result array = a1 
		else if (idx1 < n1 && idx2 < n2 && a2[idx2] > a1[idx1])
		{
			result[idx3] = a1[idx1];
			cout << "increment idx1" << endl;
			idx1++;
		} 
		//we ran out of elements for n1
		else if (idx1 == n1)
		{
			result[idx3] = a2[idx2];
			cout << "a1 ran out, increment idx2" << endl;
			idx2++; 

		}
		//ran out for n2
		else if (idx2 == n2)
		{
			result[idx3] = a1[idx1];
			cout << "a2 ran out, increment idx1" << endl;
			idx1++; 
		}
	
	}
	//size of new array
	return n1+n2;  
}


int main()
{
	//makeMerger test cases 
	// string x[5] = { "cheryl", "krieger", "lana", "malory", "pam" };
	// string y[4] = { "cyril", "lana", "lana", "sterling" };
	// string z[20];
	// 	int b = (makeMerger(x, 5, y, 4, z, 20));  // returns 9
	// 	cerr << "xy merger array returned " << b << endl;
	// z has  cheryl cyril krieger lana lana lana malory pam sterling

	string t[5] = { "cheryl", "krieger", "lana", "malory", "pam" };
	string bad[3] = {"zack", "anna", "malory"};
	string badz[8];
	// //one string isn't in nondecreasing order
		int n = makeMerger(t, 5, bad, 3, badz, 8);
		cerr << n << endl;

	cout << "contents of array after function" << endl;
	for (int i = 0; i < 8; i++)
	{
		cerr << badz[i] << endl;
	}
	
}

