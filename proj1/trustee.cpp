#include <iostream>
#include <string>
using namespace std;

//Shannon Hoang 
//This is yourfinalized CS project

int main()
{
    cout << "What is the name of your asset?" << endl;
    
    string assetName;
    getline(cin, assetName);
    
    
    // if assetName empty
    if (assetName == "")
    {
        cout << "---" << endl;
        cout << "You must enter an asset name." << endl;
        return 0; // program terminates if no name entered
    }
    
    // assetName is nonempty
    cout << "What is the value of your asset?" << endl;
    
    double assetValue;
    cin >> assetValue;
    
    if (assetValue < 0)
    {
        cout << "---" << endl; //for aesthetics
        cout << "The asset value must be nonnegative." << endl;
        return 0;
    }
    
    cout << "Which category would you like to store this asset under?" << endl;
    
    // consume newline from cin
    cin.ignore(10000, '\n');
    
    string categoryName;
    getline(cin, categoryName);
    
    if (categoryName == "")
    {
        cout << "---" << endl;
        cout << "You must enter an asset category.";
        return 0;
    }
    
    double trusteeFee = 0; // variable to be used later
    
    // holds how much money is taxed at the first amount
    double firstTaxBracketAmt;
    
    // need to tax only up to the first million
    if (assetValue <= 1000000)
    {
        firstTaxBracketAmt = assetValue;
    }
    else
    {
        firstTaxBracketAmt = 1000000;
    }
    //tax rate for first 1000000 is 1.3%
    trusteeFee += firstTaxBracketAmt * 0.013;
    

    // need to tax only next 9 million
    // how much is being taxed in 2nd portion
    double secondTax; // variable to be used later
    if (assetValue <= 10000000)
    {
        secondTax = assetValue - firstTaxBracketAmt;
    }
    else
    {
        secondTax = 9000000;
    }
    
    //if category is mutual fund or royalty tax is .02%  instead of 1% (normal tax rate)
    if (categoryName == "mutual fund" || categoryName == "royalty")
    {
        trusteeFee += secondTax * .002;
    }
    else
    {
        trusteeFee += secondTax * .01;
    }


    // if asset value needs to be taxed at third bracket
    if (assetValue >= 10000000)
    {
        double thirdTax = assetValue - 10000000;
        trusteeFee += thirdTax * 0.009;
    }
    
    // rounding
    cout.setf(ios::fixed);
    cout.precision(0);
    
    cout << "---" << endl;
    cout << "The trustee fee for " << assetName << " is " << trusteeFee << endl;
    
    return 0;
}
