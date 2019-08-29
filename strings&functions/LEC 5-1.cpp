// LEC 5-1
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
		numberOfDigits++;
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
			digitsOnly += pn[k]; //append pn[k] to the end of digitsOnly one at a time 
	}
	return digitsOnly;
}


// This is useful because writing code in increments makes it less likely that bugs happen
// predicate - a function that returns a boolean, common to name them like predicate of a sentence
// want function that phone is a valid phone number 
// translates to bool isValidPhoneNumber (string pn);

//Common mistake 
//bool wants you to return true or false, but there's nothing that defines false 
//undefined behavior 
bool (f ~~) 
{
	for (~~)
	{
		if (~~)
		return true; 
	}
}

// += operator example with string 
string s = "Hello";
s += ' '; 
s += "there";
s += 7; //an integer doesn't work, what's added has to be a char or a string 

// two ways to represent a line, cartesian coordinates (x,y) or polar coordinates (dist from origin and angle)
// let's write. afunction 

// a function cannot return two doubles with our knowledge 
void polarToCartesian (double rho, double theta, double xx, double yy)

int main ()
{
	double r; 
	double angle; 
	//... get values for r and angle...
	double x; 
	double y; 
	polarToCartesian (r, angle, x, y);
	...
	double x2; 
	polarToCartesian (2*r, angle, x2, y);
	...
}

//WRONG!!!
//Normally, arguments are copied into the corresponding parameter. "pass-by-value"
//The results end up in the wrong place and are just disposed
void polarToCartesian (double rho, double theta, double xx, double yy) 
{
	xx = rho * cos(theta);
	yy = rho * sin(theta);

}

//The right way is to give the function access to the original x and y 
//Arguments can be passed by reference -- the parameter is another nme for the argument, not a copy of it
// using & 

void polarToCartesian (double rho, double theta, double& xx, double& yy)
{
	xx = rho * cos(theta);
	yy = rho * sin(theta);

}

// note: rho and theta are "passed by value" -- > copied
// xx and yy are passed by reference --> a reference is just a nme for an already existing object; no copy is made 

// if not passed by reference, copies disappear with the function 
void exchange (int& x, int& y);

int main()
{
	... 
	int a; 
	int b; 
	cin >> a >> b; 
	if (a < b)
		exchange(a, b);
	cout << a << " is at least as big as " << b << endl;
	...
}

void exchange (int& x, int& y);
{
	int t = x; 
	x = y; 
	y = t;
}

// Another string example
// What should I censor? My SSN is 877-39-6539
// function should print My SSN is ***-**-****

int main()
{
	cout << "What should I censor? "; 
	string msg; 
	getline(cin, msg);
	cout << censoredString(msg) << endl; 
}

//note that the name suggests what the result is 
//version 1 
string censoredString(string s)
{
	string result = " ";
	for (int k = 0; k != msg.size(); k++)
	{
		if (isdigit (s[k])) // if the position isdigit append a *, censor 
			result += '*';
		else
			result += s[k]; // if at the position anything else, let it be 
	}
	return result; 
}

//version 2
//how about better way? 
//pass in an arg, and it returns a new string with the answer 
string censoredString(string s)
{
	string result = " ";
	for (int k = 0; k != msg.size(); k++)
	{
		if (isdigit (s[k])) // if the position isdigit append a *, censor 
			s[k] = '*';
		
	}
	return s; 
}

//version 3 
//passed by reference 
cout << "What should I censor?";
string msg; 
getline (cin, msg)
cout << msg << endl; 

//changes the original object 
void censor (string& s)
{
	for (int k = 0; k != msg.size(); k++)
	{
	if (isdigit (s[k])) // if the position isdigit append a *, censor 
		s[k] = '*';
	}
}

// There are several approaches
// leave the string alone change copies and return copies 
// leave the string alone and then put the result in another variable 
// leave the string alone until you replace it with the censored version

//save reference parameters that really need them! 


// Chars in many cases can be treated as small int values 

char thing = 'w'; 
int q = 23; 

char ch = 76; //'L' if ASCII is the encoding, '<' if EBCDIC 
int k = 'L'; //76 if ASCII, 211 if EBCDIC 
ch++; // now 77; 'M' if ASCII, '(' if EBCDIC

//guaranteed: 'a' < code for 'b' ... code for 'y' < code for 'z'
//code for 'A' < code for 'B' ... code for 'A' < code 'Z'
//NOT GUARANTEED TO BE CONTINUOUS so 'B' won't necessarily be one more than 'A'
//code for '1' is one more thn the code for '0'
//code for '2' is one more than '1'
//code '9' is one more than the code for '8' 
//THESE ARE YOUR ONLY GUARANTEES

Application : 
string s = "Hello";
//this works
if (s[1] < s[2])
// s[1] and s[2] are both chars, don't need to be converted to integers 

//example 
string s = "Hello there";
//method 1
if (s[k] >= '0' && s[k] <= '9')
//method 2 (better)
if (isdigit(s[k]))

//Another example 
char ch = 76; 
int k = 'L';

ch++; //now 77, 'M' if ASCII '(' if EBCDIC 
k = 77; 
double x = 3.7; 

cout << x; //calls the function for. double; '3 '.' '7'
						//if ASCII, this is 51 46 55 
						//if EBCDIC, this is 243 75 247 
cout << k; //calls the function for an int; writes '7' '7'
						//if ASCII, this is 55 55 
						//if EBCDIC, this is 247 247 
cout << ch; //calls the function for a char; writes 'M' if ASCII, '(' if EBCDIC 
						//the character whose code is 77, if ASCII this is 77
						// if EBCDIC, this is 77

                        //you set a character equal to an int, but you asked to print out a char so developer will try to do that 

dec -> bin
0 -> 0000
1 -> 0001
2 -> 0010
3 -> 0011
4 -> 0100
5 -> 0101
6 -> 0110
7 -> 0111
8 -> 1000




