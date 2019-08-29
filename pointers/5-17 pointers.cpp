//5-17 pointers

//When to use pointers vs reference? 
//most of the time reference 

double &b // is not a double b but a reference to a double named b 
double *p //not a double named p but a pointer to a double named p 


//example
//a 5.1 <--- p 
//b 3.2 <--- q 

double a = 5.1;
double b = 3.2;
double* p = &a; 
double* q = &b; 
//initialize a pointer double//q and r point to the same double
double* r = q;

*p = b; //*p points to a reference to a, which leads to a, which is a double


//p = &b; //change p to point to b
//p = q; // this works also  

//you can compare two pointers 
//the values in a and b are the same but the memory addresses are diff
if (p == q)//FALSE

if (q == r)//TRUE, they both point to b 

//*p points back to a= 3.2 and so does q* points to b=3.2 
if (*p == *q) //true, comparison of two doubles 
//when pointers point to same object, they're equal 

//Application of pointers - traverse an array 

const int MAXSIZE = 5; 
double da[MAXSIZE]; 
int k; 
double* dp; //declare a double pointer called dp 

/*  each one is 8 bytes more than previous
da [0] [1] [2] [3] [4] [5(imagined)]

*/ 

//one way of doing things 
for (k = 0; k < 5; k++){
	da[k] = 42; 
}

//do with pointers 
//&da generates a pointer to da[0] and sticks it in dp
//dp++ shifts what is being pointed to 
//an array name all by itself generates a pointer to position 0 of array
//&da[0] = da; &da[5] = da+number of elements 
for (dp = da;dp < da+MAXSIZE;dp++)
	*dp = 42; 

//& and * are inverse in a sense, they cancel each other out
// *&x -> x
//*dp = 42 
// *&da[0] = 42
// da[0] = 42 


//what does dp++ mean 
dp = dp +1
dp = &da[0] +1 
dp = &da[0+1]
dp = &da[1]
//advances pointer to the next item 


//comparisons of pointers 
&a[i] + j // &a[i+j]
&a[i] < &a[j] // position i less than position j; works for other operators 
if (&a < &b) //WRONG; don't compare pointers in different arrays 

//C++ guarantees that you generate a pointer one past possible positions
//in an array, but you can't follow it


//an array name all by itself generates a pointer to position 0 of array
&da[5]
&da[0+5]
&da[0]+5
da+5 





















