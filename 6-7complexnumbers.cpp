
class Complex 
{ 
	public:
		Complex(double re, double im);
		Complex(); 
		double real() const; 
	private: 
		double m_rho; 
		double m_theta; 
}; 

Complex::Complex(double re, double im)
{
	m_rho = sqrt(re*re* +im*im)
	m_theta = atan(im, re); 

}

//default constructor 
//how do you call default constructor? --> Blah bd; 
//BUT Blah f(); compiles, but it's not right 
//if you do f.foo(); this is illegal since f. is a function 
//be careful! 

Complex::Complex()
{
	m_rho = 0; 
	m_theta = 0; 

}

double Complex::real()const 
{
	return m_rho * cos(m_theta); 

}


int main() 
{
	Complex c1(4,-3); //represents 4-3i
	Complex c2; //represents 0+0i
	cout << ct.1real(); //writes 4 
	...
	Complex ca[100];
	...
}


// ..you can overload a function name if the functions differ in the numbers or types of parameters
//these two are fine 
void draw(Rectangle r)
{

}

void draw(Circle c)
{

}

int main()
{
	Rectangle x; 
	Circle y; 

	draw(y);
	draw(42); //Error! won't compile, no appropiate function 
}


////////------------------////////---------------////////-----------////////
void f(int i, double d);
void f(double x, int y); 
void f(double a, double b); //adding this will override the ambiguity 

f(3.7, 42); //calls the second function 
f(3.7, 5.8); //both functions are equally "good"; ERROR! Ambiguous! 



#include <cmath>
using namespace std; 


double diag(double side)
{
	//C++98: Ambiguous before because this is an int, there's no complete matching func 
	return side * sqrt(2); 
}

//double sqrt(double x);
//float sqrt(float x); 
//long double sqrt(long double x); 



































