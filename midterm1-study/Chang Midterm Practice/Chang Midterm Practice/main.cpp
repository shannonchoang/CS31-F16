//
//  main.cpp
//  Chang Midterm Practice
//
//  Created by Shannon Hoang on 4/24/17.
//  Copyright © 2017 Shannon Hoang. All rights reserved.
//


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    const string str = "There is an Apple!";
    int count=0;
    for(int i=0 ; i != str.size() ; i++)
        if( str[i] == 'a' && isalpha(str[i]) )
            count++;
    cout << count << endl;
}


