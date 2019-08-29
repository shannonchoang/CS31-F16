//
//  main.cpp
//  if else notes
//
//  Created by Shannon Hoang on 4/14/17.
//  Copyright © 2017 Shannon Hoang. All rights reserved.
//

#include <iostream>
#include <string> 
using namespace std;

int main(int argc, const char * argv[])
{
/* you want to be careful of if and else statements pairing when you don't want them to
    for example:
 if (citizenship == "USA")
 {
    if (age >= 18) 
        cout << "You can vote in the U.S. elections" << endl;
 }
else 
    cout << "You are not a U.S. citizen" << endl;
 */
    // to combine operations using <&&> operator
    
if (citizenship == "USA" && age >= 18)
    cout << "You can vote in the U.S. elections" << endl;
    /* "short circuit and"
     if first condition is false, then 2nd condition isn't even checked
     */
   
    
// or operator; if the first part is true, the 2nd part won't even be evaluated
if (citizenship == "USA") || citizenship == "Canada")
    cout << "The country code is 1" << endl;
   
    
if (roll == 2 || roll == 3 || roll == 12)
    cout << "You lose!" << endl;
if (citizenship == "USA" || citizenship == "Canada" && age >= 65)
/* 
 && has higher precedence than or || 
 thus it's a good habit to fully parenthesize everything
 */
    
if (rating < 1 || rating >10)
{
    cout << "The rating must be an integer from 1 to 10 inclusive." >> endl;
    
}
    if (rating < 1 || > 10)) // won't compile!
    // ...
    if (citizenship == "India" || "South Korea") // won't do what you want!
        
    /*
     De Morgan's Laws
     not (A or B) ==> (not A) and (not B) 
     not (A and B) ==> (not A) or (not B) 
     
     not (a < b) ==> a >= b
     not (a <= b) ==> a > b
     not (a > b) ==> a <= b 
     not (a >=b) ==>
        
    
    return 0;
}
