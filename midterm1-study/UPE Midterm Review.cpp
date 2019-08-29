// CS Midterm Review 
/* Libraries
#include -- allows us to use a library 
Namespace- collection of classes and functions 
if we don't use namespace std; // we will have to specify everytime 

Basic data types int, double, char 
declaring variables stores values in data 
Type of variable must be specified only once. 
int x = 5;  

Modifying variables 
integer division truncates after the decimal point
The % modulus operator gets the remainder of an operation 

	Double division 
	If AT LEAST ONE of operands is a double, floating point division occurs
	If AT LEAST ONE of is an int, integer division occurs 
	=> what happens if one is a double and one is an integer..?; does it not compile?
*/ 

// Strings store blocks of texts 
string x = "hello"; 
//individual chars can be accessed with [] operator. 
char c = x[0]; 

	// getting size of string 

//String operations 
// + operator is overloaded; 
// appends to the end of strings 
int main () 
{
	string x; 
	getline (cin,x);
	cout << x << endl; 
}
//ignoring characters 
//undesirable characters are often left in the iput buffer after using cin 
// to avoid this problem use cin.ignore(int numChars, char delim)
// does getline consume '\n' -- > YES 

int x; string a; 
cout << "Enter an integer" << endl; 
cin >> x; //assume the user enters a "7"
cout << "Enter a string" << endl; 
getline (cin, a); // assume the user enters 500? 
//what prints?.. an empty string because cin and new line was entered 
//getline will read until it finds a newline 

//another useful library 
#include <cctype> 
	isalpha ('M') 

// Control Flow 
// if statements only run if the condition is true
// Note: any non-zero 

int age; 
cin >> age; 
if (age < 13)
{
	cout << "You are not a yet a teenager!" << endl;  
}

//Comparison pitfalls 
// == boolean operator, compares two operations and returns either true or flase
// = assignment operator, 

// if statements, only next line is attached unless there's curly braces 
// else statements are performed when if and else conditions fail 
// % gives remainder in integer division 

//elseif 
if (cond1)
	statement1;
else if (cond 2)
	statement 2; 
else 
	statement 3; 

//Switches -- has to be an integral type or convertible to one 
// e.g. int, char, short, long, etc. QUESTION: what is short and long
// string is not a permitted type 
// a break statement must be used to leave the switch. if you want to pair certain cases 

string value; int number;
cin >> number;
switch (number) 
{
	case 0: // fall through to Case 2 
	case 2: 
		value = "Good";
		break; // remember to break!!!!! 
	case 3: 
		value = "Bad"; 
		break; 
	default: // not required but good to catch unexpected cases, leave a comment if you don't have a default to explain why 
		value = "Ugly";
		break; // a break statement isn't required for the default case

// While loops 
int main () {
	int x = 0;
	while (x < 2 )
	{
		cout << x << endl;
		x++; 
	}
}
	cout << "Done!" << endl;
}

// Do while loops, same as while loops, except the first iteration always runs.
// TO DO: look back for do while loop at slide ..
statement1;
do {

}

//for loops 
for (declaration; condition; action) // all 3 parts are optional, but what's required are the semicolons
{
	statement 1; 
	statement 2; 
}

// Nested loops 

// Increments 
int x = 5; 
int y = x++; // int y is declared as equal to x THEN. ++ happens. 

//Breaking the outerloop? 
//What happens when you break inside nested loops
// Solution: use a boolean variable (a flag) inside your loop's statements and change the boolean from true to false when you want


// write a function that takes a string and returns the integer represented by that string. 
// write a forloop 





