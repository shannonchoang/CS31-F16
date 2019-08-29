

// copies the 5th character and shifts everything right of it
// find the bug and fix it
// "abcdefg\0" -> "abcdeefg\0"
// there its two bugs

#include <iostream>
#include <string.h>
using namespace std; 
// void copy_fifth(char* word) {
	
// 	if(strlen(word) < 5) 
// 		return;

// 	for(int i = strlen(word); i >= 5; i--) {
// 		word[i] = word[i - 1]; 
// 	}
// }

// given number of places it needs to move and number of elements in string, returns how much position changes 
int shiftBy(int toMove, int elements){
	int positionChange = toMove % elements; 
	return positionChange; 
}

//given a position, shifts char at that position to the right by one 
void shiftRight(int pos, char* word){
	char temp = word[pos + 1];//you're usually overwriting something
	word[pos] = word[pos + 1];//so it's necessary to save its value
}

void rotate (char* word, int n){
	//loop through string 
	int positionChange = shiftBy(n, strlen(word));
	cout << "position change is: " << positionChange << endl;
	//runs number of positionChanges that need to be made 
	for (int i = 0; i < positionChange; i++){
			int temp = word[strlen(word)-1]; // save char at end 
			//shift ones before over right by 1 
			for (int j = strlen(word)-1; j > 0; j--){ 
				cout << "replacing " << word[j] << " with" << word [j-1] << endl;
				word[j] = word[j-1]; //set it equal to the char before it 

			}
		// //set first = to character moved off the edge 
		word[0] = temp; 
	}

}

int main ()
{
	// char s[] = "abcdefg\0";
	// copy_fifth(s);
	// for (int i = 0; i < 7; i++)
	// {
	// 	cout << s[i] << endl;
	// }
	char a[] = {'a', 'b', 'c', 'd', 'e'};
	rotate (a, 3);
	for (int i = 0; i < 5; i++){
		cout << a[i] << endl;
	}
}
// write rotate right
// void rotate(char* word, int n)
// "abcde\0" -3> "cdeab\0"
// ""


