#include <iostream>
using namespace std; 


// Write a function which finds the position of an element inside an array, given the element’s address.
//the_ptr gives the element's address 
int findPositionInArray(int a[], int n, int * the_ptr)
{
	int position; 
	position = the_ptr - a;
	return position; 
}

int main()
{

int a[] = {1,1,1,1,1};
int * test_ptr = &a[3];

cout << findPositionInArray(a, 5, test_ptr) << endl; //should return 3 because test_ptr is at the 3rd position


}
