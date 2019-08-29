#include <iostream>
using namespace std; 


void deleteG(char* cString){
	// if the next char is not null byte
	while(*(cString) != '\0'){ 
		//if a g is found, shift everything left 
		if (* cString == 'g' || * cString == 'G'){
			char * ptr = cString; 
			while (*ptr != '\0'){
				*ptr = *(ptr+1); 
				ptr++;  
			}
		}
		else{
			cString++; 
		}
	}
}

int main(){
	char arr1[]= "\n";
	char arr2[]= "gggggg\n";
	char arr3[]= "I recall the glass gate next to Gus in Lagos, near the gold bridge.\n";
	char arr4[]= "aaaaaaaaaaaaaaaag\n";

	cout << "arr 1 prints:"
	cout << arr1 <<"|"<< endl;
	cout << "arr 2 prints:"
	cout << arr2 << "|" << endl;
	cout << arr3 << endl;
	cout << arr4 << endl;
}
