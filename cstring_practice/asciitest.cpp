//ascii test

#include <iostream>
#include <string> 
using namespace std;
 
int main()
{
    //different, valid ways of converting ASCII
	char wow = 'a'; 
	int adjf = wow;
	cout << adjf << endl; // should print 97
	char c = 'f';
	char d = 97;
	cout << (int) 'f' << endl; // should print 102 
	cout << (int) c << endl; //should print 102
	cout << d << endl; //prints a 
	cout << (char) c << endl; //converts back to character 
}
