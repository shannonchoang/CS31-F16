// returns last character of a string 
// return type is char 
// input type is string 

// Write a function named "getLastCharacter" that takes a string as input
// and returns the last character as a char

#include <iostream>
#include <string>
#include <cctype>
using namespace std; 


// input string 
// input int 
// want to return [int]

char getNthChar (int n, string str)
{
	return str[n];
}

// Write a function that takes in a string and returns nothing
// inside the function, i want you to print each character of the string
// IF THE CHARACTER IS A VOWEL USING SWITCH STATEMENTS

void printVowels (string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
			case 'a': 
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			cout << str[i];
			break;

			default:
			break;
		}
	}
}


int main ()
{
	printVowels("hello my name is ryan");
} 

char getLastCharacter (string input)
{ 
	int length = input.size(); 
	return input[length - 1]; 

}

