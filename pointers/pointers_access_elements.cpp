//common format for visiting elements in array using pointers 



const int MAXSIZE = 5; 
double da[MAXSIZE]; 
int k; 
double* dp; //declare a double pointer called dp 
//start at array name (element 0)
//stop right before  position 0 + # of elements 
for (dp = da;dp < da+MAXSIZE;dp++)
	*dp = 42; 