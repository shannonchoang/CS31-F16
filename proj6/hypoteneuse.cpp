#include <iostream>
#include <cmath>
using namespace std;

void hypotenuse(double leg1, double leg2, double* resultPtr)
{
    *resultPtr = sqrt(leg1*leg1 + leg2*leg2);
}

int main()
{
	double x;
	//p can only store addresses "&" is address of operator  
    double* p = &x; //a pointer that points to a double 
    hypotenuse(1.5, 2.0, p);
    cout << "The hypotenuse is " << (* p) << endl;
}


