#include <iostream>
#include <string> 
#include <string.h>
using namespace std; 

void string_concat(char a[], char b[]); 

int main (){

char str_1[20] = "hello\0"; 
char str_2[20] = "grape\0";

	string_concat(str_1, str_2);
	//print new array 
	for (int i = 0; i < 20; i++){
		cout << str_1[i] << endl;
	} 
}

//concatenation
//Hello and Goodbye = HelloGoodbye
void string_concat(char a[], char b[]){
	int aIndex = strlen(a);
	for (int bIndex = 0; bIndex < strlen(b); bIndex++){
		a[aIndex] = b[bIndex];
		aIndex++; 
	}
	a[aIndex] = '\0'; 
}