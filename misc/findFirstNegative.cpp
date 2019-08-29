#include <iostream>
using namespace std; 


//function which finds the address of the first negative element of an array. If no such elements exist it should return a NULL pointer.
int* findFirstNegative(int a[], int n)
{
	//is this problematic because ptr is local to the function?
	//ANSWER: no, the value of the pointer is returned
	for(int* ptr = a; * ptr != '\0'; ptr++){
		if(* ptr < 0){
			return ptr; 
		}
	}
	return NULL;

}

int* findFirstNegative2()



int main(){

int a[] = {1,1,1,1,1};
cout << * findFirstNegative(a, 5) << endl; //should return NULL because there are no negative elements in the array

int b[] = {1,1,1,-1,-1};
int * b_ptr = &b[3];
cout << * findFirstNegative(b, 5) << endl; //should return the same value as b_ptr because the first negative element occurs at the 4th location in the array.


}
