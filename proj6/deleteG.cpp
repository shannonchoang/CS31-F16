#include <iostream>
using namespace std;

//deleteG
//remove all upper all lowercase 'g' letters from the string
//the resulting string must be a valid C string
//must not declare more than one local variable in addition 
//to parameter, must be of pointer type
//do not use square brackets or cstring functions 
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
	// char arr[] = "I recall the glass gate next to Gus in Lagos, near the gold bridge.\n"; 
	// char arr2[] = "\n"; //segmentation fault 
	// char arr3[] = "absdg\n";
	char arr4[] = "ggggg\n"; 
	// char arr5[] = "gag\n";
	// char arr6[] = "fuckmeintheassgg\n";


	deleteG(arr4); 
	cout << "What's printed is: ";
	for (char * ptr = arr4; * ptr != '\n'; ptr++){
		cout << * ptr; 
	}
	cout << "|ends here" << endl;

}