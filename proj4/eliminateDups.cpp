#include <iostream>
#include <string>
#include <assert.h>
using namespace std; 

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
int main ()
{
	//duplicates test cases 
	// string dups1[6] = {"lana","malory", "malory", "malory", "sterling","sterling"}; 
	// //normal case
	//     assert(eliminateDups(dups1, 6) == 3); 
	//     assert(dups1[0] == "lana" && dups1[1] == "malory" && dups1[2] == "sterling"); 
	//no duplicates 
	string dups2[3] = {"lana", "clarice", "jenny"};
		assert(eliminateDups(dups2, 3) == 3);
	//element size is zero 
		assert(eliminateDups(dups2, 0) == 0);
	//negative number of elements 
	    assert(eliminateDups(dups2, -5) == -1);


   for (int i = 0; i < 3; i++) 
	{
  	cerr << dups2[i] << endl;
	}
    //string e[4] = {"cat", "bird", "dog", "dog"};

}
	