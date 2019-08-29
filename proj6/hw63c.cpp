#include <iostream> 
using namespace std; 

//no square brackets
//no integer variables 
 const char* findTheChar(char* str, char chr)
{
	//set ptr = to address of first ele in str 
    for (char * ptr = str; * ptr != '\0'; ptr++){
        //deref ptr, compare to char 
        if (* ptr == chr){
            return ptr; //if matching return 
        } 
    }
    return nullptr; //no match and expended cString
}

const char* findTheCharOriginal(const char str[], char chr)
{
    for (int k = 0; str[k] != 0; k++)
        if (str[k] == chr)
            return &str[k];

    return nullptr;
}


int main()
{
	char test1[4] = {'d', 'b', 'c', 'e'};
	cout << * (findTheCharOriginal(test1, 'f')) << endl;
	cout << * (findTheChar(test1, 'f')) << endl;

}
	