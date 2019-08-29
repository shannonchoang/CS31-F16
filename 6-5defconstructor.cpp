//6-5 zero arg constructor 

//"zero-arg constructor" "default constructor"

class Target {
public: 
	Target (); 
	...
};

class Pet{
public: 
	Pet(string nm, int initialHealth);
	...
};

struct Employee{
	string name; 
	double salary; 
	int age; 
}; 

//Rules for default constructor 
//if constructor not declared, compiler writes one for you 
//leaves members of built-in types unintialized 
//and default-constructs members of class types 

//this is why you see a bunch of random numbers in types int, and double 

//What about arrays?
//default constructor is used 
Employee ea[100]; 
Target ta[100];

//What about a pet array? 
//Pet doesn't have a default constructor
Pet pa[100];
//We can't have an array of pets
//BUT we can have an array of pointers to pets 
//dynamically allocating objects 

