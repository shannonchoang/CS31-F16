 
#include <iostream> 
using namespace std; 




//what is wrong with this piece of code 
//previously str1 and str2 were constants even though you wanted to increment them to loop through the strings 
void countMatches(const char *str1, const char *str2, int& count)
{
 count = 0; //why do you want to dereference an integer 
	 while (str1 != '\0' || str2 != '\0')
	 {
		 if (*str1 == *str2)
		 count++;
	 str1++;
	 str2++;
	 }
} 



int main() { 

int count1; 
countMatches("UCLA", "U$C", count1); //count1 should = 1 
cout << count1 << endl; 
// int count2; 
// countMatches("Baseball", "ballpark", count2); //should set count to 2; 
// cout << count2 << endl; 
}
