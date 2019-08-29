#include <iostream>
using namespace std;    


double computeAverage(const double* scores, int nScores)
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