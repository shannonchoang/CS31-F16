//what we've been doing = C++ strings:
//Review
#include <string> 
using namespace std; 

string t = "Hello";
string s; //empty string, not a garbage value 

for (int k = 0 k != t.size(); k++)
	cout << t[k] << endl; 

cout << t; 
getline(cin, t);

s = t; //sets s to Hello
s += "!!!"; //sets s to Hello!!!

if (t < s)
	... 

//what does it mean to compare strings? 
t: Hello 
s: Hello
//t is not less than s, but equal 

t: Hello
s: Hello!!!!
//t is less than s, it runs out before s 

t: Hello
s: Help 
//both of them have a character, but neither runs out
//"Hello" has an 'l where "Help" has a "p"
// t < s 

//cancatenate "1" to end of string
for (int k = 0; k < 1000; k++)
	s+= '!';