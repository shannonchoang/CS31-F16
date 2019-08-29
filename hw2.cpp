#include <iostream>
using namespace std; 

//TODO: ask Ryan about J
int main(){
	string * fp; // a. declare pointer variable fp that can point to a string
	string fish[5]; //b. declare fish to be 5 element array of strings
	fp = fish + 4; //c. make fp variable point to last element of fish
	* fp = "yellowtail"; //d. make string pointed to by fp equal to "yellowtail"
	*(fish + 3) = "salmon"; // e. without using fp pointer and without using square 
	fp -= 3; //f. move the fp pointer back by three strings
	fp[0] = "eel"; //h. without *, or name fish; fp[0] dereferences current pos of ptr
	bool x; 
	bool * b = &x; //j. ASK RYAN
	if (* fp == (*(fp+1))){
		* b = true; 
	}
	else 
		* b = false;

	cout << * b << endl;

	}



