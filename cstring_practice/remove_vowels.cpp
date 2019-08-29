#include <iostream>
#include <string.h>
using namespace std; 

bool isVowel(char a);
void remove(int pos, char* word);
void remove_vowels(char* word);


int main () {
	char test_cstring[] = "Hello my name is"; //should print Hll my nm s"
	remove_vowels(test_cstring);
	for (int i = 0; i < strlen(test_cstring); i++){
		cout << test_cstring[i] << endl;
	}

}

void remove_vowels(char* word)
{
	for (int i = 0; i < strlen(word);){
		if (isVowel(word[i])){
			remove(i, word);
		}
		else{
			i++; 
		}
	}
}
		

bool isVowel(char a)
{
	char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
	for (int i = 0; i < 10; i++){
		if (a == vowels[i]){
			return true; 
		}
	}
	return false; 
}

void remove(int pos, char* word)
{
	int i; 
	for (i = pos; word[i] != '\0'; i++)
	{ 
		word[i] = word[i+1]; //sets current equal to character after it 
	}
}