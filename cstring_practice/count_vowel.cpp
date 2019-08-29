#include <iostream>
#include <string> 
using namespace std; 


//counting vowels 
int count_vowels(string text){
	int count = 0; 
	char vowel[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	//loops through vowels
	for (int idxVowel = 0; idxVowel < 10; idxVowel++){
		//loops through string, checking if vowel  
		for (int idxStr = 0; idxStr < text.size(); idxStr++){
			//if current vowel is found in string 
			if (vowel[idxVowel] == text[idxStr]){
				count++; 
			}
		}
	}
	return count; 
}

int main () {
	string test = "Hello What's up";
	cout << count_vowels(test) << endl;
}