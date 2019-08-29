// a function which returns a string's length, nullbyte not included
#include <iostream>
#include <string> 
using namespace std; 
int string_length(char s[])
{
	for (int idx = 0;;idx++)
	{
		//count until nullbite 
		//count doesn't include nullbyte
		if (s[idx] == '\0')
		{
			return idx; 
		}

	}
}
//attach b to the end of a 
void string_concat(char a[],char b[])
{
	//remember that these lengths don't include nullbyte
	int alen = string_length(a);
	int blen = string_length(b);

	for (int bidx = 0; bidx < blen; bidx++)
	{
		a[bidx+alen] = b[bidx];
	}
	a[alen+blen] = '\0';
	
}
//checks if other strings are anagrams 
//characters of one string can be rearranged to spell out the other string 
//128 possible values for a character 

int moveToEnd(string a[], int n, int pos)
{
	//if elements number negative or position out of scope 
	if (n <= 0 || pos > n)
	{
		return -1; 
	}

	//save these values to use at the end
	const int originalPos = pos; 
	const string temp = a[originalPos]; 		
	for (int i = pos; i+1 < n; i++)
	{ 
		cerr << "replace " << a[i] << "with " << a[i+1] << endl;
		a[i] = a[i+1]; //sets current equal to character after it 
	}
 	a[n - 1] = temp;
	return originalPos;  
}


bool anagrams(char a[], char b[]) {

	//set up empty arrays to fill with integer values of characters 
	int NUM_ASCII = 128; 
	for (int i = 0; i < NUM_ASCII; i++){
		int	aTot[i] = 0;
		int BTot[i] = 0;
	}
	int alen = string_length(a);
	int blen = string_length(b); 
	for (int a_i = 0; a_i < alen; a_i++){
		aTot = a[ai]
		
	}

}

			//5, -1, 11, 4 
void reverse_array(int arr[],int size){
	int temp; 
	int toEnd; 
		//move current to the end 
		//delete current, shift everything to left 
		for (toEnd = 0; toEnd+1 < size; toEnd++){ 
			int temp = arr[toEnd]; //saves current to move to end later 
			arr[toEnd] = arr[toEnd+1]; //sets current equal to character after it 
		}
		//sets last char to current 
	 	arr[toEnd - 1] = temp;
	}

int main() 
{
	char s[20] = "Hello";
	cout << string_length(s) << endl;

	char test_str_1[20] = "hello";
	char test_str_2[20] = "grape";

	string_concat(test_str_1, test_str_2);
	cout << test_str_1 << endl;

	int a[] = {4, 11, -1, 5};
	reverse_array(a,4);
	cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
	//should print 5, -1, 11, 4 
}