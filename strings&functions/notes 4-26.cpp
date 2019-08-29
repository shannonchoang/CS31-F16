// 4-26 notes 

// to avoid repetition, break your program into smaller chunks so your main routine does one thing. 

void greet(int nTimes, string msg);
int square (int k); // we're just declaring the function, this is because you can't use something in C++ without using it

int main()
{
	...
	int x = square (2); 
	int y = 3 * square(x+1) + 2; 
	...
	greet(square(x-1), "Bonjour"); // greet returns 9 and Bonjour  // each function has its own set of variables. 
	int z = greet(3, "Barev"); // Error! Won't compile! greet doesn't return a value 
}


// you cannot use n = greet (3, "Hello");
// void isn't supposed to return anything 
void greet (int nTimes, string msg)  
{
	if (nTimes < 0)
	{
		cout << "Do YOU want to greet ME?" << endl;
		return; 
	}

}
for (int k = 1; k <= nTimes; k++)


int square (int k)
{
	return k*k; 
}

// We want a program that does this behavior
// Enter a phone number: (310) 825-4321 
// the digits in the phone number are 3108254321 

// takes a string, returns a bool -- only two types TRUE OR FALSE 
bool isValidPhoneNumber(string pn); 
string digitsOf (string pn);


int main ()
{
	cout << "Enter a phone number" //phone number and newline is entered 
	string phone; 
	//getline reads until newline and consumes newline, cin doesn't so it'll leave a new line
	// that issue doesn't exist here because we've just been declaring functions 
	getline (cin, phone); 

	if (isValidPhoneNumber(phone)) //we want to call a function that checks if there's 10 digits 
		cout << "The digits in the phone number are " << digitsOf(phone) << endl;
	else 
		cout << "A phone number must have 10 digits." << endl; 

}
bool isValidPhoneNumber(string pn)
{
	int numberOfDigits = 0; 
	for (int k = 0; k!= pn.size(); k++)
	{	
		if (isdigit(pn[k]))
		number of digits++;
	}	
	return numberOfDigits == 10;
;
}

string digitsOf(string pn)
{
	string digitsOnly = "";
	for (int k = 0; k != pn.size(); k++)
	{
		if(isdigit(pn[k]))
			digitsOnly += pn[k]; //append pn[k] to the end of digitsOnly 
	}
	return digitsOnly;
}


// This is useful because writing code in increments makes it less likely that bugs happen
// predicate - a function that returns a boolean, common to name them like predicate of a sentence
// want function that phone is a valid phone number 
// translates to bool isValidPhoneNumber (string pn);