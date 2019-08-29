//problem #5 from Kuang-Hua 
#include <iostream>
using namespace std;

int f(int x);
bool findRoot(int x[], int n, int root[], int &m);

int main()
{
 int x[31],root[31];
 int n = 31,m = 0;
 
 for(int i = 0;i < n ; i++)
	 x[i] = i - 15;

 if(findRoot(x,n,root,m))
 cout << "Found root for f(x)" << endl;
} 


int f(int x)
{
 // x^3 - 2x^2 - 5x + 6
 return (x*x*x-2*x*x-5*x+6); 

}

bool findRoot(int x[], int n, int root[], int &m)
{
	bool foundRoot = false;
	int i;
	m = 0;
	//loop up to nullbyte in int array 
	for (int i = 0; x[i] != '\0'; i++){
		if (f(x[i])== 0){
			root[m] = x[i]; //put root in root array 
			m++; //increment pos in root array 
			foundRoot = true; 
		}
	}
	return foundRoot; 
}