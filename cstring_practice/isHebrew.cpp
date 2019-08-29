//given an array of words, find all the "hebrew" words
//no vowels

#include <iostream> 
#include <cstring> 
#include <assert.h>
using namespace std;
 

 bool isHebrew(char arr[]) {
 	char vowels[] = "aeiou"; 
 	//loop through array 
 	for (int arrIdx = 0; arrIdx < strlen(arr); arrIdx++){
 		for (int vowelIdx = 0; vowelIdx < strlen(vowels); vowelIdx++){
 			if (arr[arrIdx] == vowels[vowelIdx])
 				return false; 
 		}
 	}
 	return true; 
 }

 int main() {
 	char test1[] = "hello";
 	cout << isHebrew(test1) << endl;
 }