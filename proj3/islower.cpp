#include <iostream>
#include <string> 
using namespace std; 


bool lowercase (char cr)
{
	if (cr > 96 && cr < 123)
	{
		
		cout << "Char is lowercase" << endl;
		return true; 
	}
	else 
	{
		cout << "Char is not lowercase" << endl; 
		return false; 
	}
}


int main ()
{

char cr;
cout << "What is your character?" << endl; 
cin >> cr;
lowercase (cr); 
return 0;

}

