   
#include <iostream>
using namespace std; 

//the pointer was only passed by value 
//therefore inside the function, only a copy was changed
//so when we returned ptr, we just passed the original which 
//is an uninitialized pointer 
    void findDisorder(int arr[], int n, int*& p)
    {
        for (int k = 1; k < n; k++)
        {
            if (arr[k] < arr[k - 1]) //item at position k is less than one before 
            {
                //set spointer to point to what is the "disorder"
                //point to whatever is at k 
                 p = arr + k; 

                 return;
            }
        }
	   p = nullptr; // otherwise make the pointer point to nothing 
    }       
        
    int main()
    {
        int nums[6] = { 10, 20, 20, 40, 30, 50 };
        int* ptr; //creates a pointer that points to an integer 

        findDisorder(nums, 6, ptr); //passes pointer into function 
	if (ptr == nullptr)
	    cout << "The array is ordered" << endl;
	else
	{
            cout << "The disorder is at address " << ptr << endl; //this just prints the address
            //this just prints the address minus the address of the first element in the array  
            cout << "It's at position " << ptr - nums << endl;
            //doesn't point to the item but whatever is at the address of the above  
            cout << "The item's value is " << *ptr << endl;
	}
    }


    //questions: 
    //how to 