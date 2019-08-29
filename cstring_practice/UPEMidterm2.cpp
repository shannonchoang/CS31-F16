//UPE Midterm 2 Review 
/*
topics
functions
arrays
cstrings
*/

//Scoping
//variables declared outside function don't exist inside
//unless they're global variable:
//defined outside of functions 

//EXAMPLE: 
	const int foo = 6;
string functionName(int a, int b) {
  cout << x << endl; // x does not exist here, so this is an ERROR.
  int y = 5 + foo;   // This is okay because foo is global.
  return y + a + b;
}
//Scoping & Switch statements 
//this results in compilation error 
int main() {
  int n;
  cin >> n;
  switch (n) {
    case 1:
      int x = 10; 
      cout << "You entered 1! 1 times 10 is " << x << endl;
      break;
    default:
	int x = 5; //this is under the same scope as x = 10
      cout << "You didn't enter 1" << endl;
  }
}
//to fix (create a scope)
switch (n) {
    case 1: {
      int x = 10; // Now x is only known to the scope of this case
      cout << "You entered 1! 1 times 10 is " << x << endl;
      break;
    }
    default:
      cout << "You didn't enter 1" << endl;
  }


//Find the first character in string 1 that exists in string2 
char firstChar(string1, string2) {
  for (int i = 0; i < string1.size(); i++)
    for (int j = 0; j < string2.size(); j++)
      if (string1[i] == string2[j])
        return string1[i];
  return ‘\0’;
}

//Parameters 
//without &, it's just a copy
//modifiers: &m const, *(pointers), etc

//Will this compile? 
//Assume this function is defined later.
bool isEqual(string s1, string s2, int position); 

int main() {
  string s1 = "hello";
  string s2 = "there";
  int position = 1;
  string x = isEqual(s1,s2);
}
//missing position, and the type is boolean

//Passing by value 
//by default all parameters in C++ are pass by value
//values COPIED into the function 

bool containsLowercase(string s);

int main() {
	  string s1 = “really long string”;
	  containsLowerCase(s1);    // a copy of s1 is made and 
}                           // passed to containsLowerCase}


//Pass by reference 
//reference to variable is passed to function instead of copy
//if changed inside

//Does this function properly swap the two variables passed
void swap(int x, int y) {
  	  int temp = x;
  	  x = y;
  	  y = temp;  
}
//no. only the copies are being swapped 

//Const variables
//parameter with constant modifier can't be modified within funciton 
bool isPrime(const int& num) {
  // Cannot change value of num here.
  ...
}
//uses: assures user parameter won't be changed
//usually passed by reference (&) 
//avoid copying, save memory 


//Arrays
//valid declarations
int arr[10]; //declare an array with type, name and [size]
bool list[5]; //same with booleans 
const int MAX_SIZE = 10; 
string words[MAX_SIZE]; //must be a constant variable
int arr[] = {1,2,3}; //without size declared but elements


//rules for specifying size
//must be in brackets unless implicitly given thorugh 
//contents immediately included
//cannot involve varaible unless constant known at compile time 

//passing array to functions
//typically have to pass size of array
//name is pointer to first element in array 


//Out of Bounds Errors
//arrays indexed at 0, 

//Do we have an out of bounds memory access here?
// Assume arr only contains n elements.
int countFives(int arr[], int n) {
  int count = 0;
  for (int i = 0; i <= n; ++i) {
    if (arr[i] == 5) {
      count++;
    }
  }
  return count;
}
// i <= n, it will attempt to access nth element of the array
//but because we start at zero, we only have up to n-1

//CStrings - a character array 
string x = "hello";
x.size() //this is okay in c++
char y[] = "hello";
//cannot use c++ string functions with it 
// y.size(), y.substr(..), etc. //syntax errors 

//#include <cstring> provides functions like strlen 

int x = 'G'; //x is now 71 
x -= 1; //x is now 70
char y = x // y is now F 
int z = '5'; //z is now 53


//note arr[i] != '\0'; and arr[i] != 0 are the same, 
//ascii value of '\0' is 0


char x[50] = "hello"; 
//if we read this it would stop at nullbyte
//you can also overwrite 




