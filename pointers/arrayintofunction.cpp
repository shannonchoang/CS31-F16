//when an array is passed to a function
//you're passing a pointer to the array 


//it looks like you're saying a is an array but 
// in reality you're declaring a pointer 
// double * a would work the same way 
double f (double a[], int n){
	double total = 0; 
	for (int i = 0; k < n; k++){

		total += a[k]; 
	}
	return total; 
}

//note you would pass in 
double sum = f(da,5);
			f(&da[0], 5);


//when declaring an array and intializing
double x[3] = {10, 20, 30}; 
double y[] = {10, 20, 30}; // the compiler will automatically count and fill it in