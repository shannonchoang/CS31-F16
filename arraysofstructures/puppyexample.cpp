#include <iostream>
#include <string>
using namespace std; 

//array of structures example 
struct Puppers{
	string name; 
	string hair_color; 
	int age; 
} my_puppies[100]; //DON'T FORGET SEMICOLON

void printPupper(Puppers puppy)
{
	cout << puppy.name <<"'s haircolor is " << puppy.hair_color << endl;
	cout << puppy.name << "is " << puppy.age  << endl;
}


int main() {
	for (int i = 0; i < 3; i++){
		cout << "Enter pupper name: ";
		//object of same struct type.name of member of that type 
		getline(cin,my_puppies[i].name);
		cin.ignore(10000, '\n');
		cout << "What is their hair color?";
		getline (cin, my_puppies[i].hair_color);
		cin.ignore(10000, '\n');
		cout << "How old are they?"; 
		cin >> my_puppies[i].age; 
	}

	cout << "Here are your puppies and their information" << endl; 
	for (int i = 0; i < 3; i++){
		printPupper(my_puppies[i]);
	}

}




