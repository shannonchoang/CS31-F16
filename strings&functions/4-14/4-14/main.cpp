//
//  main.cpp
//  4-14
//
//  Created by Shannon Hoang on 4/14/17.
//  Copyright © 2017 Shannon Hoang. All rights reserved.
//
/*
 if (condition) 
    statementIfTrue
 else
    statementIfFalse
 
 or  -- if you just want it to continue if false
 if (condition) 
    statementIfTrue
 */

#include <iostream>
using namespace std; 
int main(int argc, const char * argv[]) {
    const double PAYRATE_THRESHHOLD = 12.00;  // adding <const> allows you to just keep the value the same
    const double HIGH_WITHHOLDING_RATE = 0.10;
    const double LOW_WITHHOLDING_RATE = 0.05;
    
    // Gather input data
    cout << "How many hours did you work?";
    double hoursWorked;
    cin >> hoursWorked;
    
    cout << "What is your hourly rate of pay?";
    double payRate;
    cin >> payRate;
    
    // Compute and print earnings and withholding
    double amtEarned = hoursWorked * payRate;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "You earned $" << amtEarned << endl;
  
    double withholdingRate;
    if (payRate >= PAYRATE_THRESHHOLD)
    {
        withholdingRate = HIGH_WITHHOLDING_RATE;
    }
    else
    {
        withholdingRate = LOW_WITHHOLDING_RATE;
    }
    cout << "$" << (withholdingRate * amtEarned) << " will be withheld." << endl;
    
       /* double withholdingRate= 0.10; (this is wrong you won't be able to use this variable outside the curly braces)
        declaration 
        type variable; 
        type variable = expression;
        
        assignment statement
        variable = expression;
        
        magic constant - a number that used but isn't explained why
        don't have a bunch of random numbers mixed into your program
        better to have declared as variables, commonly capitalized
    
    */


    return 0;
}

