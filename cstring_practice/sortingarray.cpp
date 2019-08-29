
#include <iostream> 
#include <string> 
#include <string.h> 
using namespace std; 

//Sorting an array--sorts an array of integers into ascending order 
void sort_array(int arr[], int size)
{
	//loop through the array, increment curr min pos each time 

	//default min is at position 0 
	for (int curr_min_pos= 0; curr_min_pos < size; curr_min_pos++){
		//find minimum 
		int oldMinpos = curr_min_pos;
		int currMin = arr[curr_min_pos];
	
		for (int idx = curr_min_pos;idx < size; idx++){
			//if next smaller, update current min 
			if (arr[idx+1] < currMin){
				currMin = arr[idx+1];
				oldMinpos++;
			}
		}
		int temp = arr[curr_min_pos];
		arr[curr_min_pos] = currMin; //replace with current minimum 
		arr[oldMinpos] = temp;
	}
}
	

int main()
{
	//expect -1 as min
	//-1 and 5 should switch 
	//-1,1,5,6,3
	int arr[6] = {-7, 5, 1, -1, 6, 3};
	sort_array(arr, 5);
	for (int i = 0; i < 6; i++) 
	{
		cout << arr[i] << endl;
	}
	// cout << arr[0] << endl;
	// cout << arr[4] << endl;


}

