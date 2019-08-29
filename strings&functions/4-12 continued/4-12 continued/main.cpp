//
//  main.cpp
//  4-12 continued
//
//  Created by Shannon Hoang on 4/12/17.
//  Copyright © 2017 Shannon Hoang. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "How many hours did you work?";
    double hoursWorked;
    cin >> hoursWorked;

    cout << "What is your hourly rate of pay?";
    double payRate;
    cin >> payRate;
    
    double amtEarned = hoursWorked * payRate;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "You earned $" << amtEarned << endl;
    if (payRate >= 12.00)
    {
        cout << "$" << (0.10 *amtEarned) << " will be withheld." << endl;
    }
    else
    {
        cout << "$" << (0.05 * amtEarned)<< " will be withheld." << endl;
    }
    return 0;
}

    /*
     if (condition)
     statementIfTrue
     else
     statementifFalse 
     
     
     types of conditions: >= greater than or equal ("at least," "no more than") ; <= less than or equal ("at most," "no more than")
     not equal  !=
     equal      ==
     
     Compound Sentence
     {stment;stment;stment;
        */

/* cout << "What is your name?";
string name;
getline(cin, name);
if name (== "")
cout << "You didn't type a name!" << endl;
else
cout << "Hello," << name << endl;

 cout << "What is your hourly rate of pay?"; 
 double payRate; 
 cin >> payRate; 
if (payrRate < 10.00) 
 cout << "Ask for a raise!" << endl; 
 
 for instance 
 if payRate >= 100.00) 
 { 
 cout << "You make ";
 cout << "Good living!" << endl;
 } 
 * if you want to group the two statements together use the curly braces to enclose them
 
 Assignment statement 
 Takes a variable that is already declared, and put a value in it 
 
 <variable = expression;>
 
 */

