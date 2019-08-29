//CONSTRUCTOR////
//FUNCTION called automically whenever an object is created 



//do not declare return type 
//naming convention is it's the same as class 
class Target{
//any part of the program can talk about these members 
public: 
	Target(); //declares a position 
	void init(); //initializes the target
	bool move(char dir); //move target
	void replayHistory(); 
	int position();
//only the member types of Target can talk about history and pos
//most parts of the program won't have access to
private: 
	//Invariant: 
	//history consist of only Rs and Ls 
	//pos == # of Rs in history minus # of Ls in history 
	int pos; 
	string history;
}; 


//EXAMPLE CONSTRUCTOR 
//sets initial value to something good 
Target::Target(){
	pos = 0; 
	history = "";
}

//if you have an array of objects
//and constructor, the constructor is being called
//number of elements in array 
void playGame(){
	Target targets[1000];
	int nTarget=0;
	if (...)
		addTargets(targets,nTargets,3);
		//once you leave addTargets, pointers deleted, left with object garbage 
}

//DYNAMIC STORAGE APPLICATION -- during runtime 
//new name_of_type
//create a brand new object of that type
//call constructor to initialize and call a pointer to it 

//Target is an array of pointers 
//only create objects when you need them 
//do something cheap like create 1000 unintialized pointers 
void addTargets(Target* ta[], int& nt, int howManyNewOnes){
	for (int k =0; k < howManyNewOnes; k++){
		ta[nt] = new Target; 
		nt++; 
	}
} //garbage, allocated memory for it but no way of using it 
//delete p; give back the object pointed to by p
//that pointer is a dangling pointer 

//let's say you want to move target right 
targets[i]->move('R');
//pointer of class type->
//object of class type. 


//PASSING ARGS INTO CONSTRUCTOR 
Employee::Employee(string nm, double sal)
{
	name = nm; 
	salary = sal; 
}

Employee e("Fred", 60000)

//an array of employees --DYNAMICALLY ALLOCATING, creating new objects 
Employee * company[100]; 
company[--] =  new Employee(-,-); //dynamically allocate a new employee




