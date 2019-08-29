#include <iostream>
#include <string>
#include <cctype>
using namespace std; 

//Tongue twisters
// tongue twister: sentence in which more than half of the words 
// begin with the same letter as the first letter of the first word.

bool isTongueTwister(char arr[], int n)
{
	//find first letter 
	char firstLetter = tolower(arr[0]);
	int letterCount = 0; 
	int wordCount = 0; 
	//loop through the sentence 
	for (int i = 0; i+1 < n; i++){
		//if new word found
		if (arr[i] == ' '){  
			wordCount++;
		}
		//if new word and first letter = to first letter
		if (tolower(arr[i+1]) == firstLetter){
			letterCount++; 
		}
	}
	if (letterCount > wordCount/2){
		return true; 
	}
	return false; 
}

int main()
{
	char seashells[40] = "Hello my name is"; 
	cout << isTongueTwister(seashells, 40) << endl;
}