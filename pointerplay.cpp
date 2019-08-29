#include <iostream>
using namespace std; 



int main(){
	int arr[] = {1, 2, 3};
	int* p = arr; 

	cout << p << endl; // p is the memory address
	cout << * p << endl; // * p points to the object 

	* p += 1; 
	cout << * p << endl; //you can increment the pointer 

	//try to alter the value using the pointer 
	* p = 9; //pointer currently points to element at position 1 in array 
	cout << * p << endl; //this will print out 9 but not actually change what is at position 1, it is merely changing what the pointer points to to integer 9

	cout << arr[1] << endl;//this proves that it has not changed


	p = 9; 

	cout << arr[1] << endl;//this proves that it has not changed

	// * p = arr; //why doesn't this work
	int* b = arr; 
}
