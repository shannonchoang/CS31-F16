//
//  main.cpp
//  cin_notes
//
//  Created by Shannon Hoang on 4/14/17.
//  Copyright © 2017 Shannon Hoang. All rights reserved.
//

/*
getline Notes:

getline(cin, str_variable);

Memorize: get a line of input from cin and stores it in str_variable
reads until and including newline character into str_variable and removes it from cin

i.e. lets say that cin contains the following:
"hi my name is ryan\n poopoo butt"

getline(cin, str_variable);
str_variable now contains "hi my name is ryan"
cin now contains " poopoo butt"
 
Note: if cin contains a newline at beginning of buffer
 i.e. cin = "\n poop"
 then getline gets nothing and just destroys the newline in cin
 
cin >> var notes:
Memorize this - '>>' reads until it finds non whitespace
 stores nonwhitespace into var until whitepsace
 all characters read into the var are removed from cin
 
 i.e.
 cin contains this "     my     dick"
 string var;
 cin >> var;
 
 var now contains: "my"
 cin now contains: "       dick"
 
 another in example:
 cin >> str_variable;
 str_variable now contains "hi"
 cin now contain " my name is ryan\n poopoo butt"
 
When to use cin.ignore('\n', 10000);

We use this when we wish to destroy a newline so getline can
 get a full line of text
 
i.e.
 lets say cin contains the following:
    "3\nfuck me up fam\n"
 and we wish to read 3 in to an integer and fuck me up fam into a string
 
 int temp;
 string temp_str;
 
 
 cin >> temp;
 // cin now looks like this = "\nfuck me up fam\n"
 // to get rid of the newline, we use cin.ignore
 cin.ignore('\n', 10000);
 getline(cin, temp_str);

*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "hello world" << endl;
    string temp;
    
    cin >> temp;
    cout << temp;
    return 0;
}
