
//promise to not change 
//evaluate whether or not it's "too expensive" to pass by reference 
//AKA a huge array 
void printPaycheck(const Employee& e); //e is another name for Employee 
void celebrateBirthday(Employee& e); //by reference, want to modify original object
double totalPayroll(const Employees emps[], int nEmps);

int main(){
	Employee company[100];
	int nEmployees = 0; 
	...read in some info, fill array, set nEmployees
	printPaycheck(company[1]); 
	celebrateBirthday 

void printPaycheck(Employee& e){
	cout << "Pay to the order of " << e.name << " the amount of $" << e.salary/12 << endl;
	// e.salary *= 1.1; //this won't compile, we made a promise that e will not modify employee 
}

//USING structures with arrays 
//the caller of the function will generate a pointer to company sub 1 
void celebrateBirthday(Employee* ep){
	//we want to select the object that ep points to 
	//*ep.age++; //this will not compile, the dot operator has higher precedence than star operator 
	//also the dot operator requires that on the left, must be an object of some structure type 
	(*ep).age++; //this works, but it's ugly 
	ep->age++; //the arrow operator, 

	/*SYNTAX: 
	a pointer to object of some struct type -> the name of member of that type 
	*/
}
//assume in company we have 
/* 
0		1		2		3
"Fred" "Ethel" "Ricky"
60000	50000	40000
42		37		39
*/ 

double totalPayroll(const Employee emps[], int nEmps){
	double total = 0; 
	for (int k = 0; k < nEmps; k++){
		total += emps[k].salary;
	}
	return total; 
}

