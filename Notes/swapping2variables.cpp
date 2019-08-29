//
//  main.cpp
//  4-28 DISC

#include <iostream>
using namespace std;
void swap (int a, int b) // this function will swap two variable values
{
    int c = a;
    a = b;
    b = c;
    
}
int main ()
{
    int x = 10, y = 5;
    cout << x << " " << y << endl;
    swap(x,y);
    cout << x << " " << y;
}

