
//LEC 5-31
//We want to keep track of information about our employees 
//but the problem is, every element in an array has to be of the same type, a name is a string, an age is an int, etc 


//this would work, but there's nothing in the code explicitly referring to an employee 
string name[100];
double salary[100];
int age[100];

//creating a type -- when u make your own, capitalize (style)
//defining a new type, what it means to be an employee 
struct Employee
{
	string name[100];
	double salary[100];
	int age[100]; 
}; //DON'T FORGET THE SEMICOLON!!

//What the things inside are called: 
//members, fields, attributes, instance variables

int main()
{
	Employee e1; //current name is ""; other two values are garbage values
	Employee e2; //current 

	e1.name = "Fred"; //selects the particular member name of object Employee 
	e1.salary = 60000; //selects salary under e1 sets = 60000
	e1.age = 42; 

	e1.age++; //what does this do? age for e1 is now 43 

	cout << "Enter a name: ";
	getline(cin, e2.name);  
	cout << "Enter a salary: "; 
	cin >> e2.salary; 
}

//SYNTAX: 
// an object of some struct type . the name of a member of that type 
