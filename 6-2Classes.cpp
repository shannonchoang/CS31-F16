//Protecting members of a class 


class Target{
	public: 
	//...can be used by anyone 
	private: 
	//..only member functions can access
	//how we protect certain members
}; 

//remember when you use string.size
//string is a class type and a member is its size, 


//every member function has a pointer called this which is a 
//pointer to the object it is calling 

//DATA ABSTRACTION (info hiding, encapsulation)
//forbid users from writing ode that directly affects those portions
//how does string work? we don't know & don't need to 


//only make things member functions if they need access to the private 
//data

class Target{
//any part of the program can talk about these members 
public: 
	//which functions are allowed to alter the members 
	//member functions, operations, methods 3
	void init(); //initializes the target
	bool move(char dir); //move target
	void replayHistory() const;//replay history doesn't modify the object 
	int position() const;//function promises not to modify the object called
//only the member types of Target can talk about history and pos
//most parts of the program won't have access to
private: 
	//Invariant: 
	//history consist of only Rs and Ls 
	//pos == # of Rs in history minus # of Ls in history 
	int pos; 
	string history;
}; 

//putting const here prevents it from being modified
//note the position 
int Target:: position() const {
	return pos; 
}

void Target::replayHistory()
{
	for(int k = 0; k != this->history.size(); k++){
		cout << this->history[k] << endl;
	}
}

//this can be correctly implemented without any private members s
void repeatMove(Target& x, int nTimes, char dir){
	for (int k = 0; k< nTimes; k++)
		x.move(dir);
}

//pass in t2- -4, "LLLL"
//passing by value isn't very economical; add const to protect from modifyi

//THIS WOULDN'T COMPILE, because you're calling a function on it
//compiler wouldn't know if function modifies it or not 
//compiler is not allowed to look at implementation of function 
//--it's too expensive to check everything  
void report (const Target& x){
	cout << "There's a target at position" << x.position() << endl; 
}

//window for bad Target 
//before it's initilaized it has garbage values
//we want to eliminate this we want something that as soon
//as target is created, object is created

//CONSTRUCTOR////
//FUNCTION called automically whenever an object is created 



