#include <iostream>
using namespace std; 

// return true if two C strings are equal
//previously, the pointers themselves were being compared
//not the characters that are being pointed to
bool match(char str1[], char str2[])
{
    char* ptr1 = str1; 
    char* ptr2 = str2; 
    while ((* ptr1) != '\0'  &&  (* ptr2) != '\0')  // zero bytes at ends
    {
                                    //what it does: compares the addresses
        if ((* ptr1) != (* ptr2))  // compare corresponding characters
            return false;
        ptr1++;            // advance to the next character
        ptr2++;
    }
    return * ptr1 == * ptr2;   // both ended at same time?
}

int main()
{
    char a[10] = "pointed";
    char b[10] = "pointed";

    if (match(a,b))
        cout << "They're the same!\n";
}
