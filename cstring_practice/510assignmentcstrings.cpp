//is this allowed?


		0     1    2    3    4 ..... 
string s[49] = {'H', 'e', 'l', 'l', 'o', '\0'}



double da1[5];
double da2[5]; 

da2 = da1; 
//ERROR! this won't compile, the language doesn't allow this
//to copy one array into another, you need a loop 
//because array is made of several characters 

//there is a function 
strcpy(s,t); // <strcpy(destination, source)>


char ca[3];
char s[6]; //Hello + zerobyte
//the destination has to be large enough
strcpy(ca, s); // error! undefined behavior! 

strcpy(ca, "AB"); //string literals work 

strcat(s, "!!!"); //this works provided both are proper cstrings and there's room 

//comparison 
if (t < s) //COMPILES but WRONG!! 

if (strcmp(t,s) < 0)
	strcmp (a,b)
		negative if a comes before b    < 0 if a is less than b 
		0 if a equals b 			    ==0 if a equals b 
		positive is a comes after b 	> 0 if a greater than b 

//C++ strings 
if (t >= s)
// C strings
if (strcmp (t,s) >= 0) //this would return 
//general syntax
< if (strcmp(a,b) OP 0) 


is a equal to b
 Wrong: if (strcmp(a,b)) // actually yields the opposite result
 //returns false even if equal; look at comparison
 		if (strcmp (a,b) == 0)

//c++ string
void makeUpperCase(string& s)
{
	for (int k = 0; k != s.size (); k++)
		s[k] == toupper(s[k]);
}
//c string 
//the only difference is detecting the end of the string, using the null byte 
void makeUpperCase(char s[])
{
	for (int k = 0; s[k] != '\0'; k++)
		s[k] == toupper(s[k]);
}

