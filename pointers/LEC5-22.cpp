int findFirstNegative(double a[], int n) 
{
	for (int k = 0; k < n; k++)
	{
		if (a[k] < 0)
			return k; 
	}
	return -1; 
}

int main()
{
	double da[5]; 
	...
	int fnpos = findFirstNegative(da, 5); 
	if (fnpos == -1) 
		cout << "There are no negative values in the array" << endl; 
	else {
		cout << "The first negative value is " << da[fnpos] << endl; 
		cout << "It's at position number " << fnpos << endl; 
	}
}
//What does a pointer version of this look like 


//Pointer subtraction just means how far ahead one pointer is in an array than the other 
//function that finds the first negative in an array 
int findFirstNegative(double a[], int n){  
	//p will start with a's value; points to object 0
	//n is number of elements  
	for (double* p = a; p < a+n; p++){
		if (*p < 0)
			return p - a; //p is the address of &da[2] and a is the address of &da[0] 
	}
	return -1; 
}	
//NOTE: &a[i] < &a[j] --> i < j
// &a[i] + j --> &a[i+j]
// &a[i] - &a[j] -- > i - j
//a pointer to a[i] minus a pointer to a[j] is the same as i-j 


//what if you want to return a pointer to first negative int 
double* findFirstNegative(double a[], int n) 
{
	for (double* p = a; p < a+n; p++){
		if (*p < 0)
			return p;
	}
	return nullptr; //nullptr you need something of pointer type; 
					//you can't follow it, it points to no object
}



int main()
{
	double da[5]; 
	...
	double* = findFirstNegative(da, 5); 
	if (fnpos == nullptr) 
		cout << "There are no negative values in the array" << endl; 
	else {
		cout << "The first negative value is " << *fnp << endl; 
		cout << "It's at position number " << fnp  - da << endl;
		 //da just means a pointer to element 0, (just the position)
		//fnp points to position of first neg value; thus fnp - da = difference between positions, 
	}
}


