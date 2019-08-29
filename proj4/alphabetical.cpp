#include <iostream>
#include <string>
#include <assert.h>
using namespace std; 

bool alphabetical (const string a[], int n)
{ 
	for (int i = 0; i < n; i++)
	{
		if (!(a[i] < a[i+1]))
		{
			return false;
		}
	}
return true;
}


int main()
{
	string fruits[5] = {"avocado", "apples", "banana", "papaya", "pears"}; //not alphabetical
	cout << alphabetical(fruits, 5) << endl;
}