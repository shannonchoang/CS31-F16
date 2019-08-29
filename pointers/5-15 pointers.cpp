//Pointers 
/* 
Another way to implement passing by reference
Another way to transverse arrays
Manipulate dynamic storage
Represent relationships in data structures 
*/ 

//another way to pass by reference

// a function cannot return two doubles with our knowledge 
void polarToCartesian (double rho, double theta, double* xx, double* yy);

int main ()
{
	double r; 
	double angle; 
	//... get values for r and angle...
	double x; 
	double y; 
	polarToCartesian (r, angle, x, y);
	...
	double x2; 
					//generate a pointer  
	polarToCartesian (r, angle, &x, &y);
	...
}

//WRONG!!!
//Normally, arguments are copied into the corresponding parameter. "pass-by-value"
//The results end up in the wrong place and are just disposed
void polarToCartesian (double rho, double theta, double* x, double *y) 
{
	xx = rho * cos(theta);
	yy = rho * sin(theta);

}

//The right way is to give the function access to the original x and y 
//Arguments can be passed by reference -- the parameter is another nme for the argument, not a copy of it
// using & 

void polarToCartesian (double rho, double theta, double& xx, double& yy)
{
	//xx doesn't work, it can't hold a double 
	*xx = rho * cos(theta);
	*yy = rho * sin(theta);

}

//as the name of a type: 
// double   double
// double & reference to double
// double*  pointer to double

//&x "generate a pointer to x" "address of x"
//*p "the object that p points to" "follow the pointer p" 

// &x "generate a pointer to x"



//imagine the houses are the doubles
//you can put the address on a piece of paper == pointer
//you cannot put a person in a piece of paper
//don't mistake address for the house 
double a = 3.2; 
double b = 5.1; 

double* p = &a; 
double* q= 7.6; //WRONG! 7.6 is a double, but variable type is pointer
double c = a; // this is fine 
double d = p; //P is only a pointer type d is a double, p doesn't hold a value 

double d = *p; //this works because *p points back to 3.2 (a)
double& dd = d; //dd is a reference not a pointer
				//references once set to a double.data type, it is forever 
//pointers can be changed though

//what did the user want?
p = b; // WRONG you can't take a double that holds the address of a double and hold value 

//maybe meant 
*p = b; //assigning one double to another //take b and store it in what p points to 
		//changes value of a

p = &b; // point to value at b 

*p += 4; //*p is the object that p points to  //p* -> b = 5.1 so 5.1+4 = 9.1, b=9.1 now 

int k; 
p = &k; //p is a pointer to double, &k is pointer to an int 
		//int is 4 bytes, double is 8 bytes, too long, memory assigned incompatible

double x; 
int k = 7; 
x = k; 

int k; 
int*z = *k; 



