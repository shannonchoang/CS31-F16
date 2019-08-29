
//LEC 5-31
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

    //declare variable of type Employee 
	Employee company[100]; //we want to element at position 2 equal to employee Ricky 
	company[2].name = "Ricky"; //remember: object of same struct type.name of member of that type 

	//we want to write Ricky vertically 
	//select element at position 2 in company, select the name string
	for (int k = 0; k != company[2].name.size(); k++){
		cout << company[2].name[k]<<endl;
	}

}
