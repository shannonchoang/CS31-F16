
#include <iostream>

int main()
{
    int numberofEs = 0;
    for (int k = 0; k != t.size (); k++)
    {
        if t[k] == 'E' || t[k] == 'e'
            numberOfEs++;
    }
    cout << "The number of Es (upper and lower case) is " << numberofEs << endl;
    
    string s = "Hello";     // s is a string; "Hello" is a string literal
    char c = s[1];          // c is a (char initiliazed to lower case e)
                            // 'e' is a character constant
   
    'B' 'w' '$'  ' ' '4' '\t' '\n' '\'' '\\' 

    cout << "She said, \"Hello!\", then left."; // she said, "Hello!"" then left. 
    
    return 0;

    // be careful of using distinguishing between backward slashes (\) and forward slashes (/)
    // for instance, '\n' not '/n' 

    //remember that a char is one character 'a' it's more like an integer in which you use '' 
    // string is more like sentences, in english you usually use ""
    char c = 'x'; // OK! 
    char c = "x"; // ERROR! won't compile!  
    string = "x"; // OK! 
    string s = 'x'; // ERROR! won't compile! 

    // let's say we want to get a phone number
    // We don't' care how it's written we just want ten digits 
    // i.e. (310) 825-4321 is okay 
    // 3108254321; 310.825.4321.

    cout << "Enter a phone number: ";
    string phone; 
    getline(cin, phone); 

    if (......)
        cout << "A phone number must contain 10 digits."
 }

 int numberOfDigits = 0; 
 for (int k = 0; k != phone.size (); k++) 
{ if ( isdigit (phone[k])
    numberOfDigits++; 

} 
if (numberOfDigits != 10)
    cout << "A phone number must contain 10 digits." << endl; 


/* isdigit(ch) '0' '1' '2' ... '9'
 is lower(ch) 'a' 'b' 'c' ... 'z'
isupper(ch) 'A' 'B' 'C' ... 'Z' 
isalpha (ch) 'a' ... 'z' 'A ... Z'  will be true if it's an uppercase letter or a lowercase letter 

! A not 
A && B and 
A || or 
*/ 

// transforming upper to lower case or vice versa 
string s; 
getline(cin, s); 

// <s[0]> stands for position zero, the first character 
// hello -> Hello
// otherwise, it'll leave the specified alone

s[0] = toupper(s[0]); 

// what you can do with toupper 
// toupper won't change the original! YOU have to do that. You can store that new uppercase character somewhere else 
char c = toupper(s[0]); 
char c = toupper(s[0]); 
    if (toupper(t[k]) == 'E')

//big mistake people make, this doesn't do anything  
//this doesn't store it anywhere, this doesn't print the result 
toupper(s[01]); 

/* let's say you want to use toupper(s[01]);
with é 
it doesn't translate very well... you might get é- > E 
*/

// Memorize:
// <return-type> <function-name> (<argument1-type> <argument1-name>, ..., <last-arg-type> <last-arg-name>) {
//     <function-body>   
//     return somevalue;
// }

// keep your main function clean
// function prototype, tells the compiler it exists
// declare n 
void greet (int n, string msg); 
{ 
    // write hello 3x 
    for (int k = 0; k < 3; k++)
        cout << "Hello" << endl; 

    return; 
}
int main () 
{ 
    ... 
    ...
    greet (3, "Hello");
    int m; 
    cin >> m; 
    greet (2*m-1, "Ni hao"); 
    ...
    ...
    string s; 
    getline(cin, s); 
    greet (l,s);
    ...
    ...
}
// void just does its job and it doesn't return anything back to you 
void greet (int n, string msg) 
{
    for (int k = 0; k < 3; k++)
        cout << "Hello" << endl; 
}

int fuckMeInTheAss (int n) 
{
    return n + 1;
}



