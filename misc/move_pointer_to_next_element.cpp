#include <iostream>
using namespace std; 


// Write a function which moves a pointer in an array to point to the next element of the array
//ptr_to_ptr is a pointer that points to a pointer to an integer  
void move_pointer_to_next_element(int** ptr_to_ptr)
{
	//when you derefenced ptr_to_ptr once, you have a pointer to the element address
	//deref twice and you have the value 
	if(**ptr_to_ptr != '\0'){
		*ptr_to_ptr += 1; //set ptrtoptr equal to address of next element 
		// *ptr_to_ptr = *ptr_to_ptr+1;
	}
	ptr_to_ptr = NULL;
}

int main(){
int c[] = {1,2,13,4,5};
int * moving_ptr = &c[1]; //pointer to pointer of first element in array -- we want to point to next 
cout << "Value at moving_ptr = " << (*moving_ptr) << "\n";
move_pointer_to_next_element(&moving_ptr);
cout << "Value at moving_ptr = " << (*moving_ptr) << "\n";

// Should print out:
// Value at moving_ptr = 2
// Value at moving_ptr = 13



}
