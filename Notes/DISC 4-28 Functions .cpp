type name (arg 1, arg 2...)
{
	statements
	return 0;	// if the main function is missing this, the compiler assumes this
}


type: type of value (e.g. int, double, string, etc) returned by the function
name: identifier for calling for function 
arguments: arg 1, arg2, i.e. int x, int y, notice arguments are specificed like variable declarations <type name> 
body: bunch of statements 

//using or calling functions 
Two ways 
1) Have the whole body of the function 
2) You can declare it, then you can put the definition at the end of the pgoram 


int add(intx, int y); // declared first
int main()
{
	//literals 
	int a = add(1,2);
	cout << a << endl; //3

	//userinput 
	int a, b, c;
	cin >> a >> b;
	int c = add(a,b);
	cout << c << endl; // ?

	//w/0 saving result 
	cout << add (2,4) // 6
}

//calculates hypotenuse length 
#include <iostream>
#include <cmath> // new library for std::sqrt 
using namespace std;
 
 double square (double x){
 	return x * x; 
 }

 int main ()
 {
 	double a, x, y, d; 
 	cin >> x >> y;
 	a = square(x)
 }

 /* pass by value vs. pass-by-reference 

 when the execution space is created: 
 value: argument values are copied into the function space. The original arguments are unchanged. Q: what does this mean?
 reference: argument variables are passed directly into the function space and can change upon exit 
 */

// this is an INCORRECT example 
// this tries to swap by value rather than by reference
 #include <iostream>
 using namespace std;
 void swap (int a, int b) 
 {
 	int c = a;
 	a = b;
 	b = c;

 }
 int main ()
 {
 	int x = 10, y = 5; // these values are limited to this scope 
 	cout << x << " " << y << endl;
 	swap (x,y);
 	cout << x << " " << y; 
 }

// does this print anything? YES 

int g (int x);

int main ()
{
	cout << g[5] << endl;
	cout << g[-3.2] << endl; // = 3
	cout << g ['c'] << endl; // this is fine because c converts to a number (99) ['cc'] is compilable, you'll get some weird result, it corresponds to a table                                                                                          
}
int g (int x)
{
	cout <<x<<endl;
	return x = x * x;

}

//another example 

//note, had to put &after double in the function prototype because without it the variable would only be modified locally

using namespace std; 
int main 
{
	string s= "stringz";
	//print out the first 3 characters of s 
	cout << s.substr(0, 10) << endl;

	//print out 3 characters of s following index 2, including the character at index 2 
	cout << s.substr(2,3) << endl;

	//print out all characters of s 
	cout <s.subtr (0, s.length(str)) << endl;
}

}
