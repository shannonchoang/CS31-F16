#include <iostream>
#include <string>
#include <string.h> 
using namespace std; 

//anagrams

bool anagrams(char a[], char b[]);
int main(){
	string a1 = "cinema";
	string b1 = "iceman"; 
	char A[5];
	char B[5];
	for (int i = 0; i < 5; i++){
		A[i] = a1[i];
		B[i] = b1[i];
	}
	cout << anagrams(A, B) << endl;

}

//reads two cstrings and sees if they are anagrams of each other 
bool anagrams(char a[], char b[]){
	//create tally 
	
	int NUMASCII = 128; 
	int ASCII_A[128];
	int ASCII_B[128];
	//set up ASCII arrays to tally number of each character
	//start them at 0 
	for (int i = 0; i < NUMASCII; i++){
		ASCII_A[i] = 0;
		ASCII_B[i] = 0; 
	}

	int size_of_a;
	int size_of_b;
	size_of_a = strlen(a);
	size_of_b = strlen(b); 

	for (int a_i = 0; a_i < size_of_a; a_i++) {
	ASCII_A[(int) a[a_i]]++; //increment that digit representing that char on ASCII tally
	}
	for (int b_i = 0; b_i < size_of_b; b_i++){
	ASCII_B[(int) b[b_i]]++; 
	}

	//loop through the ascii tallys, if not equal at any point return false
	for (int i = 0; i < NUMASCII; i++){
		if(ASCII_A[i] != ASCII_B[i])
			return false; 
	}
	
	return true;
}
