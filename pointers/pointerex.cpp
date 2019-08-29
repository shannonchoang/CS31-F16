
#include <iostream>
using namespace std; 

const int MAXSIZE =5; 
double da[MAXSIZE];
int k; 
double* dp; 

for (k = 0l k < MAXSIZE; k++)
	da[k] = 42; 

for (dp = da; dp < da + MAXSIZE; dp++)
	*dp = 42; 

dp +=1; 
dp = dp +1; 


double *p; 
//never follow an uninitialized pointer 
*p = 3.7; //this alone leads to undefined behavior! *p is unintialized!
