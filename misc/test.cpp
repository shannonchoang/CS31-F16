#include <iostream>
#include <string> 
#include <cassert>
#include <cctype>
#include <cstring>
#include <stdlib.h> //atoi 
using namespace std; 

int main()
{
int array[10] = {4, 6, 2, 3, -1, -3, 2, 2, -7, -9};
int index;
cin >> index; // Enter a digit here.
int *p = array + index;
for (int i = 0; i < 5; i++)
{
 int hops = *p;
 p += hops;
}
cout << *p << endl;

}