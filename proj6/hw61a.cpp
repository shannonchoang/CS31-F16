
#include <iostream> 
using namespace std; 

 int main()
    {
        int arr[3] = { 5, 10, 15 };
        int* ptr = arr;

        *ptr = 10;          // set arr[0] to 10
        // *ptr + 1 = 20;      // set arr[1] to 20 //invalid expression 
        //correct way 
        *(ptr + 1) = 20; //creates temporary pointer that points to first element 


        ptr += 2;		//changes the pointer to point to element 2 
        ptr[0] = 30;        // set arr[2] to 30 // NOTE *(ptr+i) = ptr[i] 

        while (ptr >= arr) //while pointer(starts at 2) is pointing past array or equal to (0)
        {
            cout << ' ' << *ptr << endl;    // print values
                 ptr--; //this was previously above, needs to be underneath 
        }
	cout << endl;
    }
