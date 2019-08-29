 #include <iostream>
using namespace std;




 //array is a local variable on stack, 
//when we return there's no guarantee the value 
//won't be overwritten by something else -- junk 
int* computeSquares(int& n)
{
    int arr[10];
    n = 10;
    for (int k = 0; k < n; k++)
        arr[k] = (k+1) * (k+1);
    return arr; 
}

void f()
{
    int junk[100];
    for (int k = 0; k < 100; k++)
        junk[k] = 123400000 + k;
}

int main()
{
    int m; //declare an integer called m 
    //initialize pointer that points
    //result of computeSquares 
    int* ptr = computeSquares(m); 
    f();
    for (int i = 0; i < m; i++)
        cout << ptr[i] << ' ';
}