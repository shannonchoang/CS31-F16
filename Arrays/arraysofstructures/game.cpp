//there's nothing protecting members in Target
//some combos are invalid
//updating one without the other 

//Classes are an expanded concept of data structures: like data structures
//they can contain data members, but they can also contain functions as members.

//if you use key word Structure: everything is public by default
//keyword Target is opposite 
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
