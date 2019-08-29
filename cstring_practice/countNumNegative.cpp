
#include <iostream>
#include <string>
using namespace std; 


int countNumNegativeNumbers(int a[], int n){
	//loop through the array 
	int negNumcount = 0; 
	for (int i = 0; i < n; i++){
		if (a[i] < 0)
			negNumcount++; 
	}
	return negNumcount;
}

//returns minimum value in the array 
int getMinValue(int a[], int n){
	int currMin = a[0];
	for (int i = 0; i < n; i++){
		if (currMin >= a[i]){
			currMin = a[i]; 
		}
	}
	return currMin; 
}

int main()
{
	int a[] = {5, 2, -1, 6, 3, -7, -4}; 
	cout << countNumNegativeNumbers(a, 7) << endl;
	cout << getMinValue(a, 7) << endl; 



int k[10] = {2, -1, 2, 7, 3, -2, -1, 1, -7, -3};

int steps = 0;
int j;
cin >> j; // user enters a number.
	while (j >= 0 && j < 10) 
	{
		j += k[j];
	    steps++;
	}
  cout << steps << endl;
}