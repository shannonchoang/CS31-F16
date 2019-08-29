//switch statement practice


#include <iostream>
using namespace std;

int main()
{
    char stopLightColor; // stoplight color is red
    stopLightColor = 'R';
    
    // remember that switches can only work with ints and chars, i.e. 'a' or '3'
    // R for red, etc
      
    switch (stopLightColor)
    {
        case 'R':
            cout << "Stop!" << endl;
            break;
            
        case 'Y':
            cout << "Slow down!" << endl;
            break;
            
        case 'G':
            cout<< "Let's gooooo!!!!!" << endl;
            break;
            
    }

    int choice; 
    cin >> choice; 
    ... // means this can be filled in with something
    switch (choice)
    {
        case 1: 
        ...        //note that curly braces are not needed 
            break; // if <break;> isn't there, the compiler will read case 2 next;
        case 2:   //case 2 and case 4 will do the same thing; 
        case 4: 
        ...
            break; 
        case 3: 
        case 5: 
        ...  
        default : // means not one of the cases 
    }

/* we want this 
How many times do you want to be greeted? 3 
*/
    cout << "How many times do you want to be greeted? "; //why is there a space 
    int nTimes; 
    cin >> nTimes; 
    
    int n = 0;
    while (n < nTimes)
    {
        cout << "Hello" << endl;
        n = n + 1;
    }

    
 
    return 0;
}
