//DISC 5-19
//Review of pointers

//when you declare a variable
//you're taking a slot of memory
myvar =25; 
foo = &myvar; //this doesn't give you 25 but the address
bar = myvar //this gives you 25


//Pointer Syntax
base type * pointer name; 
//base type defines type of variable 
//the pointer points to

int * ptr1 //pointer to integer
int ** ptr2 //pointer to pointer 
int * ptr1, ptr2 // a pointer and an integer

//a function that finds the position of an element 
//inside an array, given the element's address 
int findPositionInArray(int a[], int n, int * the_ptr)
{
	int * ptr2 = the_ptr;
	return ptr2; 

}

int main(){
	int a[] = {1, 1, 1, 1, 1}; 
	int * test_ptr = &a[3]; //pointer that points to "1"
	findPositionInArray(a,5,test_ptr); //should return 3
}