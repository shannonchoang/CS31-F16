#include <iostream>
#include <string>
using namespace std;  

//DO MORE OF THESE PRACTICE PROBLEMS
// 1. WRITE A FUNCTION
// 2. TRACE WHAT IT DOES AND PREDICT THE OUTPUT
// 3. COMPARE WITH OUTPUT

// ls - lists all files in current folder
// cd <directory-name>  - change directory to the directory containing your code
// g++ <cpp-file name> - compiles your cpp code
// ./a.out - runs the binary generated from compiler

int calcProfit (int swipesSold) // swipesSold = num_swipes;
{
	int firstCalc = 7 * swipesSold;
	return firstCalc;
}

string fuckMe(string consent)// consent = "yes"
{
	string answer; 
	if (consent == "yes")
	{
		answer = "let's do it";	
	}
	else 
	{
		answer = "no means no";
	}
	return answer;
}


int main ()
{
	int num_swipes;
	cout << "How many swipes did you sell?" << endl;
	cin >> num_swipes; 
	cout << "You made $" << calcProfit (num_swipes) << endl;


	cout << fuckMe("yes") << endl; 
	cout << fuckMe ("no") << endl;
 	return 0;
}

