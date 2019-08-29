
//local variable 

Blah *p; 
int x; 


void f(){
	int y; // local variable 
	p = new Blah; 
	...y...
}

void g()
{
	delete p; 
}

int main()
{
	f(); 
	g()
	..x...
}

/*local variables (automatic variables)
live on the stack 
deleted upon exiting function

dynamically allocated objects live on "the heap"
exist until deleted 
but no way to access unless you have a pointer to it 

global variables -- 
declared outside of any function live in "global storage area" (static storage)
*/ 


class Pet {

	public: 
	Pet(string nm, int initialHealth); //constructor
	Pet(string shelter); //another constructor --pick one based on parameters given 
	~Pet(); //destructor -- called when objects are destroyed  
	string name() const; 
	void addToy(); //adds a new Toy
		...
	private: 
	// string name; bad version 
	string m_name; 
	int m_health;
	Toy* m_favoriteToy;  
}; 


class Toy {
	...
};//DO NOT FORGET 


//Pet x("Fido", 10)
//Pet y; this doesn't compile because arguments?
//Pet * pp = new Pet("Nemo", 5);
Pet::Pet(string nm, int initialHealth){ //you can give arguments to constructors 
	name = nm;
	health = ???; 
	m_favoriteToy = nullptr; //note that pet currently doesn't have a favorite toy 
}

//you can have more than one constructor for a class 
//but they must differ in either number or types 
Pet::Pet(string shelter)
{
	// ..contact the shelter named by the argument, jhave them give you a pet, and initialize 
	// the name and health to what they tell you 
}

//ERROR! this won't compile! 
//You already have a data member with this name--lang doesn't allow 
string Pet::name() const {
	return name; 
}
//How do we solve this?
/*CONVENTION: 
less intuitive name goes to data member 

something like: 
name_ 
health_ 

m_name
m_health 

*/

void Pet::addToy(){
	//another example of dynamic allocation 
	//this helps us avoid the creation of garbage, calling delete
	//gives it a nullptr value 
	delete m_favoriteToy;  //if already nullptr, this is harmless 
	m_favoriteToy = new Toy; 
}

/*for Pet x("Fido", 10);
x.addToy(); --> we will create a new Toy and store it in favorite Toy 

problem: what if addToy is used more than once? we create garbage.
Memory Leak - loses the last pointer to something, over time 
Available memory is wasted 
You won't see the problem unless the program runs for a very long time  

*/ 

Pet::~Pet(){
	delete m_favoriteToy; 
}



