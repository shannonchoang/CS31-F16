//Cstrings  -- a character array 
#include <cstring> // a number of Cstring manipulation functions 
using namespace std;

//How do I store a string that doesn't fill the entire array it's being put into?
//How do we know how many interesting elements there are?
//use nullbite (zero byte) -- byte whose ascii value happens to be 0 (\'0')
// 		0  1   2   3   4   5
// // 'H' 'e' 'l' 'l' 'o' '\0'

char t[10] = "Hello"; 
//when you declare a character array and are initializing 
//a double quoted string literal it is implied each character belongs
//to a [] in an array 
//note the \0 is implied 

char s[50]; // character is built in type, the values will be garbage 
char s[50] = " "; //initialized to all the chars in the string and a nullbite

//remember the number of elements in an array can never change 


//how to print out the letters in an array 
//condition for detecting end of cstring 
for (int k = 0; t[k] != '\0'; k++)
	cout << t[k] << endl;

//output
//writes out every character in array up to nullbyte ('H' 'e' 'l' 'l' 'o')
cout << t; 

//input 
cin.getline(s, 100); //read a line of input into s; store a '\0' at the end 
//takes the characters inputted, reads but throws away newline, and stores nullbyte
general format: <(array, max of array)>

//functions under <cstring> 
cout << strlen(t); //writes 5 
	//probably looks like this 
	int strlen(const char x[])
	{
		int k; 
		for (k = 0; x[k] != '\0'; k++)
			;//just indicates that this is the body
		return k;
	} 

t.size() // t must be a c++ string
strlen(t) // must be a C string 

char ca[3]; // the elements of the string do not match! 
ca[0] = 'A';
ca[1] = 'B';
ca[2] = 'C'; 
int n = strlen(ca); //UNDEFINED! because it reads until zerobyte

//this will not compile! 
char ca[3] = "ABC"; //a double quoted string literal says the string and a nullbyte will be stored
 

