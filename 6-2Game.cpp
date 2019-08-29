//6/2 LEC


//a method of restricting access to the data members of a type
//only to certain functions that the designer of that type can control

//Note about changing implementation 
/*
Like when they made new cars with new engines, they couldn't change
the interface otherwise learning would have to occur 

As long as internals change without changing behavior, we don't have to 
rewrite code
*/  


class Target{
//any part of the program can talk about these members 
public: 
	//which functions are allowed to alter the members 
	//member functions, operations, methods 3
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


//target starts off at position 0 and we move left and right 
int main(){
	Target t; 
	t.pos = 0; 
	t.pos++; //move right
	t.history += 'R';

}

//the NAME of some structure type :: the name of a member of that type 
void Target::init(){
	pos = 0; 
	history = "";
}

//automatically pointer to target t 
void Target::move(char dir){
	switch (dir){
		case 'R':
		case 'r': 
			pos++; 
			break; 
		case 'L':
		case 'l':
			pos--;
			break;
		default: 
			return false;
	}
	history += toupper(dir); //concatenate to history 
	return true;
}

int Target:: position() {
	return pos; 
}

void Target::replayHistory()
{
	for(int k = 0; k != this->history.size(); k++){
		cout << this->history[k] << endl;
	}
}
