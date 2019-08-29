
#include <iostream> 
#include <string> 
using namespace std; 


//reverse an array 
//4, 11, -1, 5 becomes 5, -1, 11, 4 
void reverse_array(int arr[], int size){
	//REMEMBER: the first position on the right isn't the size, but size-1
	int right = size - 1; 
	for (int left = 0; left <= (size/2) && right >= (size/2); left ++){
		//swap the values 
		int temp = arr[left]; 
		cout << temp << endl;
		arr[left] = arr[right];
		arr[right] = temp; 
		cout << "what's in left after: " << arr[left] << endl;
		right--; //deincrement right index 
	} 
}

int main(){
	int numbers[4] = {4, 11, -1, 5}; 
	reverse_array(numbers, 4);
	//prints out the new array 
	for (int i = 0; i < 4; i++){
		cout << numbers[i] << endl;
	}
}