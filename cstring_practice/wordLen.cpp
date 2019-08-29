//word len

#include <iostream>
#include <string>
#include <string.h> 
#include <cctype>
#include <assert.h>
using namespace std; 


int wordLen(int pos, char arr[]){
	//loop through word in crib, starting from a letter 
	int wordLen = 0;
	for (int i = 0; i < strlen(arr); i++){
		for (int wordLen = i; wordLen < strlen(arr) && isalpha(arr[wordLen]);){
			wordLen++;
		}
		if (wordLen > 0){
			return wordLen; 
		}
	}
return wordLen;
}


int main(){
	char a[] = "H---ello---";
	assert(wordLen(0,a) == 1);
	assert(wordLen(2,a) == 4);
 
}