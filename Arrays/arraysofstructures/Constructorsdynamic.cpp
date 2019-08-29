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
}

//DYNAMIC STORAGE APPLICATION 
//new name_of_type
//create a brand new object of that type
//call constructor to initialize and call a pointer to it 
void addTargets(Target* ta[], int& nt, int howManyNewOnes){
	for (int k =0; k< howManyNewOnes; k++){
		ta[nt] = new Target; 
	}
}
