//storingvalsinarray


#include <iostream> 
#include <string> 

int main() 
{
	//repeatedly prompt user 
	//stores values in an array starting at position 0 

	//elements in array 
	int n; 

	cout << "How many fruits are in your basket?" << endl;
	cin >> n;

	string fruits[n];  
	for (int i = 0; i < n; i++)
	{
		string fruit; 
		cout << "Which fruit would you like to store?" << endl;
		cin <<  fruit;
		fruits[i] = fruit; 
	}

} 