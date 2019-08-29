#include <iostream>
#include <string> 
using namespace std; 


//racecar should return true 
//loop from both ends of the string 
bool is_palindrome (char a [], int n){
	int right; 
	//loop from the left and right, check chars on both side equal  
	for (int left = 0, right = n; left < (n/2) && right > (n/2); left++){
		right--; 
		if (a[left] != a[right]){
			return false; 
		}
	}
	return true; 
}

int main(){
	char word[7];
	string a = "otto"; 
	//sets up the array 
	for (int i = 0; i < 4; i++){
		word[i] = a[i]; 
		//reads out char in that position
		cout << word[i] << endl;
	}

	cout << is_palindrome(word, 4) << endl;
}



