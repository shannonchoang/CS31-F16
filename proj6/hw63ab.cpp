#include <iostream>
using namespace std; 



//doesn't increment ptr 
//no square brackets 
//must use int variable to visit each double in arr 
double computeAverage(const double* scores, int nScores)
{
    const double* ptr = scores;
    double tot = 0;
    int idx = 0; 

    while (idx < nScores)
    {
        tot += *(ptr+idx);
        idx++;
    }
    return tot/nScores;
}

double originalcomputeAverage(const double* scores, int nScores)
{
    const double* ptr = scores;
    double tot = 0;
    while (ptr != scores + nScores)
    {
        tot += *ptr;
        ptr++;
    }
    return tot/nScores;
}

//REQUIREMENTS: 
//return same result, but doesn't use square brackets 
//uses integer variable k, cannot use cstring functions

// This function searches through str for the character chr.
// If the chr is found, it returns a pointer into str where
// the character was first found, otherwise nullptr (not found).

char* findTheChar(char* str, char chr) //return type is a ptr that points to a char
{
	//creates a pointer that points to str+k, increment k 
    for (int k = 0; *(str+k) != '\0'; k++)
        if (* (str+k) == chr) //dereference ptr and compare the values 
            return str+k; //if equal, return pointer that points to match

    return nullptr;
}

const char* findTheCharOriginal(const char str[], char chr)
    {
        for (int k = 0; str[k] != 0; k++)
            if (str[k] == chr)
                return &str[k];

        return nullptr;
    }



int main()
{
	cout << "the original compute average function: " << endl;
	double scores1[3] = {70.0,75.0,80.0}; //avg is 75 
	cout << originalcomputeAverage(scores1, 3) << endl;

	cout << "the new compute average function: " << endl; 
	cout << computeAverage(scores1, 3) << endl;

	char test1[] = "dbce";
	cout << * (findTheCharOriginal(test1, 'f')) << endl; //ORIGINAL
	cout << * (findTheChar(test1, 'f')) << endl; //MY FUNC





}