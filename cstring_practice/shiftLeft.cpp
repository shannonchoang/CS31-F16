#include <iostream>
#include <string>
using namespace std; 

//shift left
void shiftLeft(char arr[], int n){
	//save first
	char temp = arr[0];
	for (int i = 0; i+1 < strlen(arr);i++ ){
		//set every character equal to the one after it 
		arr[i] = arr[i+1];
	}
	arr[strlen(arr)-1] = temp; //bring deleted first to end 
}



int main(){
	char a[] = "hello"; 
	shiftLeft(a, 5); 
	for (int i = 0; i < 5; i++){
		cout << a[i] << endl;
	}

}