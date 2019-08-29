#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int moveToEnd(string a[], int n, int pos)
{
    // ...repeatedly move whatever is after pos to left
    // ...excluding the current
    if (n < 0)
    {
        return -1;
    }
    const int originalPos = pos;
    const string temp = a[originalPos];
    for (int i = pos; i +1 < n; i++)
    {
        cout << "replace " <<a[i]<< "with " << a[i+1] << endl;
        a[i] = a[i+1];
    }
    a[n-1] = temp;
    return originalPos; 
}

int main()
{
    //moveToEnd tests
    string people[3] = { "malory", "lana", "sterling"};
    //move lana to the end
    moveToEnd(people, 3, 1);
    assert(moveToEnd(people, 3, 1) == 1);
    //temp
    cout << "final list" <<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << people[i] << endl;
    }
}


