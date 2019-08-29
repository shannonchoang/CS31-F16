#include <iostream>
#include <string.h>
using namespace std; 


//shifting elements in an array 
//given pos, shifts elements after to the right 
///BAD EXAMPLE, you end up copying same char many times 
void BadshiftRight(char arr[], int start){
	char temp = arr[strlen(arr)-1];//save last value 
	for (int i = start; i < strlen(arr); i++){
		cout << "switching " << arr[i] << "with " << arr [i-1] << endl;
		arr[i] = arr[i-1]; //set = to one before it
	}
	arr[0] = temp; 
}
//GOOD example,
// note if you shift left, don't increment
void shiftRight(char arr[]){
	char temp = arr[strlen(arr)-1];//save last value 
	for (int i = strlen(arr); i > 0; i--){
		arr[i] = arr[i-1]; //set = to one before it
	}
	arr[0] = temp; 
} //"youwilldogreat" -> tyouwilldogrea





int main()
{
	char arr[] = "youwilldogreat"; 
				//tyouwilldogrea

	//switch o with y


	shiftRight(arr); 

	for (int i = 0; i < 14; i++){
		cout << arr[i] << endl;
	}
}
