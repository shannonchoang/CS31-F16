 //LEC //arrays
string names[5] = {"Fred", "Ethel", "Lucy", "Ricky", "Little Ricky"}; 

char pets[5][7] = 
{
	"cat", "mouse", "ferret", "eel", "horse"
};

//column number 
const int MAX_NAME_LEN = 6; 
int tally (..a, int n, int targetLength)

int main () 
{
	const int MAXPETS = 5; //row number 
	//the +1 next to max adds visual reminder of zero byte 
	char pets[MAXPETS][MAX_NAME_LEN+1]= {
		"cat", "mouse", "ferret", "eel", "horse"
	}; 

	for (int i = 0; k < 5; k++)
	{
		cout << pets[k] << endl;
	}

	cout << tally(pets,MAXPETS, 5); //writes 2 because 2 strings are of length 5

}

int tally (const a[][MAX_NAME_LEN], int n, int targetLength)
{
	int total = 0; 
	for (int k = 0; k < n; k++)
	{
		//remember strlen only applies to cstrings 
		//you cannot use (pets[k]) in strlen, it wasn't passed in
		//the array is called "a" in here
		if (strlen(a[k]) == targetLength)
			total++; 
	}
	return total; 
}

//strlen up to but not including the zero bye


/*
a --				0 	1 	2 	3 	4 	5 	6
				0	c 	a	t	\0
				1	m 	o 	u	s 	e
				2	f 	e 	r 	r 	e 	t
				3	e 	e 	l 	\0
				4	h 	o	r 	s 	e \0 

*/

//changing values in cstring 
//example pets[0][0] = 'r'; 
//result is 'rat' in row 0 



