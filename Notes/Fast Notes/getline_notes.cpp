#include <string>
#include <iostream>
using namespace std;

int main() {
	int num;
	string str;
	
	cin >> num;
	cin.ignore(10000, '\n');
	getline(cin, str);

	cout << num << endl << str << endl;
	return 0;
}
