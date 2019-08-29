#include <iostream>
#include <string>
#include <assert.h>
using namespace std; 

//prototypes
int enumerate(const string a[], int n, string target);
int locate(const string a[], int n, string target);
bool locateSequence(const string a[], int n, string target, int& begin, int& end);
int locationOfMin(const string a[], int n);
int moveToEnd(string a[], int n, int pos);
int moveToBeginning(string a[], int n, int pos);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int eliminateDups(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max);
int divide(string array[ ],int n, string divider);


int main() 
{
	//test cases for ENUMERATE
	string animals1[4] = {"dog", "cat", "dog", "dog"};
	string dog = "dog"; 
	string cat = "cat"; 
	string bird = "bird"; 
	//normal cases 
	assert(enumerate (animals1, 4, dog) == 3); 
	assert(enumerate (animals1, 4, cat) == 1); 
	//no elements equal to, should be 0
	assert(enumerate (animals1, 4, bird) == 0);
	//number of elements 0
	assert(enumerate (animals1, 0, dog) == 0);
	//neg number of elements
	assert(enumerate (animals1, -5, bird) == -1);
	cerr << "PASSED: enumerate" << endl; 

	//test cases for LOCATE
	string animals2[4] = {"dog", "cat", "dog", "dog"};
	//there are 3 dogs, it should return 0, because first one 
	assert(locate(animals2, 4, dog) == 0);
	assert(locate(animals2, 4, cat) == 1); 
	//no element matches target, return -1
	assert(locate(animals2, 4, bird) == -1);
	//number of elements = 0, no element matches
	assert(locate(animals2, 0, cat) == -1);
	//negative number of elements
	assert(locate(animals2, -1, cat) == -1);
	cerr << "PASSED: locate" << endl; 

	// test case for locate sequence 
	string locateNames[9] = {
	"lana", "cyril", "malory", "malory", "malory", 
	"sterling", "sterling", "malory", "malory"};
	string target = "sterling"; 
	int b;
	int e;
	assert(locateSequence(locateNames, 9, "malory", b, e) == true);//return true, b=2 and e=3 
	assert(b == 2 && e == 4);
	assert(locateSequence(locateNames, 9, "cyril", b, e) == true);//return true, b=1 and e=1
	assert(b == 1 && e == 1);
	// case where sequence ends at end of string
	assert(locateSequence(locateNames, 4, "malory", b, e) == true);//return true, b=2 and e=3
	assert(b == 2 && e == 3);
	//no string equal to target 
	b = 0; e = 0; 
	assert(locateSequence(locateNames, 9, "petty", b, e) == false);
	//number of elements = 0
	assert(locateSequence(locateNames, 0, "malory", b, e) == false);
	//negative number of elements 
	assert(locateSequence(locateNames, -3, "malory", b, e) == false); 
	assert(b == 0 && e == 0);//previously set, should be false, 
	cerr << "PASSED: locateSequence" << endl;

	//locationOfMin test cases 
	string fruits[3] = {"kiwis", "clementines", "cantalope"};
	assert (locationOfMin(fruits, 3) == 2);  
	
	string places[6] = 
	{"costa rica", "zealand", "california", "massachusetts","appalachians", "antartica" };
	 //costrica vs zealand
	assert(locationOfMin(places, 2) == 0);
	//first 3 elements 
	assert(locationOfMin(places, 3) == 2); 
	assert(locationOfMin(places, 6) == 5);
	// neg/0 input
	assert(locationOfMin(places, -1) == -1);
	assert(locationOfMin(places, 0) == -1);
	//two elements that are min 
	string stds[4] = {"herpes", "chlamydia", "crabs", "chlamydia"};
	assert(locationOfMin(stds, 4) == 1);

	// all elements are the same and are min 
	string feelings[2] = {"sad", "sad"};
	assert(locationOfMin(feelings,2) == 0);

	cerr << "PASSED: locationOfMin" << endl;


	//moveToEnd tests
	// move lana to the end 
	string ppl1[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	string ppl69[5] = {"malory", "lana", "sterling", "cheryl", "cyril"};
	assert(moveToEnd(ppl1, 5, 1) == 1 && ppl1[4] == "lana");
	for(int i = 1; i < 5 - 1;i++) {
		assert(ppl1[i] == ppl69[i + 1]);
	}
	//move cyril to the end 
	string ppl2[5] = {"malory", "lana", "sterling", "cheryl", "cyril"};
	assert (moveToEnd(ppl2, 5, 4) == 4 && ppl2[4] == "cyril"); 
	//edge case: goes beyond scope of array 
	assert (moveToEnd(ppl1, 5, 6) == -1);
	//edge case: negative element value
	assert (moveToEnd(ppl1, -5, 1) == -1);
	//edge case: n=0, examine no array elements but want to move smth 
	assert(moveToEnd(ppl1, 0, 0) == -1); 

	cerr << "PASSED: moveToEnd" << endl;
	
	//moveToBeginning tests
	// move cyril to beginning
	string ppl3[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	string ppl70[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	moveToBeginning(ppl3, 5, 4);
	for(int i = 0; i < 4; i++) {
		assert(ppl3[i + 1] == ppl70[i]);
	}
	assert(ppl3[0] == "cyril");
	//move lana to beginning 
	string ppl4[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	moveToBeginning(ppl4, 5, 1);
	assert(ppl4[0] == "lana");
	//move malory to the beginning 
	string ppl5[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	assert(moveToBeginning(ppl5, 5, 0) == 0);
	assert(ppl5[0] == "malory");
	//edge case: goes beyond array scope
	assert(moveToBeginning(ppl5, 5, 5) == -1);
	//edge case: negative number of elements
	assert(moveToBeginning(ppl5, -5, 4) == -1);
	//n=0, examine no array elements 
	assert(moveToBeginning(ppl5, 0, 0)== -1);
	cerr << "PASSED: moveToBeginning" << endl;

	//locate difference test cases
	string cast[5] = { "malory", "lana", "sterling", "cheryl", "cyril" };
	string roles[4] = { "malory", "lana", "krieger", "ray" };
	//same up to sterling/krieger
	assert(locateDifference(cast, 5, roles, 4) == 2);  
	//one runs out, return smaller 
	assert(locateDifference(cast, 2, roles, 1) == 1); 
	//elements number cannot be negative 
	assert(locateDifference(cast, -5, roles, 1) == -1);

	//one string size equal to 0 
	assert(locateDifference(cast, 0, roles, 4) == 0);
	//both string size equal to 0 
	assert(locateDifference(cast, 0, roles, 0) == 0);
	cerr << "PASSED: locateDifference" << endl;

	//duplicates test cases 
	string dups1[6] = {"lana","malory", "malory", "malory", "sterling","sterling"}; 
	// //normal case
	assert(eliminateDups(dups1, 6) == 3); 
	assert(dups1[0] == "lana" && dups1[1] == "malory" && dups1[2] == "sterling"); 
	//no duplicates 
	string dups2[3] = {"lana", "clarice", "jenny"};
	assert(eliminateDups(dups2, 3) == 3);
	//element size is zero 
	assert(eliminateDups(dups2, 0) == 0);
	//negative number of elements 
	assert(eliminateDups(dups2, -5) == -1);

    //string e[4] = {"cat", "bird", "dog", "dog"};
    cerr << "PASSED: eliminateDups" << endl;

   //subsequence test cases 
	string big1[10] = {"malory", "lana", "sterling", "cheryl", "cyril", "sterling"};
	string little1[10] = {"lana", "cheryl", "cyril"}; 
	string little2[10] = { "sterling", "lana" };
	//true case
	assert(subsequence(big1, 6, little1, 3) == true);
	//false case 
	assert(subsequence(big1, 6, little2, 2) == false);
	//0 elements big array
	assert(subsequence(big1, 0, little2, 3) == false);
	//0 elements in small array, empty subsequence 
	assert(subsequence(big1, 6, little2, 0) == true);
	//negative elements 
	assert(subsequence(big1, -6, little1, 3) == false);
	assert(subsequence(big1, 6, little1, -3) == false);
	cerr << "PASSED: subsequence" << endl;

	string t[5] = { "cheryl", "krieger", "lana", "malory", "pam" };
	string bad[3] = {"zack", "anna", "malory"};
	string badz[8];
	string res[10];
	// RYAN: uncommenting this line causes program to seg fault
	// due to line 248 only if compiled with no optimization
	// string asdff[3] = {"honey", "hujububu", "zzzz"};
	//one string isn't in nondecreasing order
	assert(makeMerger(t, 5, bad, 3, badz, 8) == -1);
	assert(makeMerger(t, 5, t, 5, res, 10) == 10);
	for(int i = 0; i < 10; i+=2) {
		assert(res[i] == res[i + 1] && res[i] == t[i/2]);
	}
	assert(makeMerger(t, 2, t, 3, res, 10) == 5);
	
	cerr << "PASSED: makeMerger" << endl;

	//divide test cases 
	string ppl6[6] = { "krieger", "cheryl", "pam", "cyril", "sterling", "lana" };
	assert(divide(ppl6, 6, "malory") == 4);  //  returns 4
	
	string ppl7[4] = { "malory", "lana", "sterling", "cheryl" };
	assert(divide(ppl7, 4, "lana") == 1);  //  returns 1

	// all elements less < divider
	string ppl8[4] = {"abigal", "anna", "cheryl", "asdf"};
	assert(divide(ppl8, 4, "zack")== 4);
	//all elements > divider, return 0
	string ppl9[4] = {"helen", "betsy", "clarice", "denis"};
	assert(divide(ppl9, 4, "anna") == 0);
	//no elements; this should return 0 
	assert(divide(ppl9, 0, "elyse") == 0);
	//negative number of elements
	assert(divide(ppl9, -4, "elyse") == -1);
	cerr << "PASSED: divide" << endl;

	string h[7] = { "malory", "sterling", "lana", "cheryl", "", "cyril", "lana" };
    assert(enumerate(h, 7, "lana") == 2);
    assert(enumerate(h, 7, "") == 1);
    assert(enumerate(h, 7, "krieger") == 0);
    assert(enumerate(h, 0, "lana") == 0);
    assert(locate(h, 7, "lana") == 2);
    assert(locate(h, 2, "lana") == -1);
    int bg;
    int en;
    assert(locateSequence(h, 7, "cheryl", bg, en) && bg == 3 && en == 3);

    string g[4] = { "malory", "sterling", "cheryl", "cyril" };
    assert(locationOfMin(g, 4) == 2);
    assert(locateDifference(h, 4, g, 4) == 2);
    assert(subsequence(h, 7, g, 4));
    assert(moveToEnd(g, 4, 1) == 1 && g[1] == "cheryl" && g[3] == "sterling");

    string f[4] = { "cyril", "cheryl", "sterling", "lana" };
    assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "sterling" && f[2] == "cheryl");

    string ee[5] = { "cyril", "cyril", "cyril", "sterling", "sterling" };
    assert(eliminateDups(ee, 5) == 2 && ee[1] == "sterling");

    string x[4] = { "cyril", "krieger", "krieger", "pam" };
    string y[4] = { "cheryl", "krieger", "lana", "sterling" };
    string z[10];
    assert(makeMerger(x, 4, y, 4, z, 10) == 8 && z[5] == "lana");

    assert(divide(h, 7, "lana") == 3);

    cerr << "All tests succeeded" << endl;

}


//DONE: returns the number of strings in array equal to target
int enumerate(const string a[], int n, string target)
{ 
	//if number of elements is 0, return -1 
	if (n < 0) 
	{
		return -1; 
	}
	//number of elements equal to target
	int targetElements = 0; 

	//for all elements in array 
	for (int pos = 0; pos < n; pos++ )
	{
		if (a[pos] == target)
		{
			targetElements++;
		}
	}
	return targetElements;
}
//DONE: return position of a string in array equal to target 
int locate(const string a[], int n, string target)
{
	//if a[pos] == string return position 
	// if not, go to next character in string 
	// if n > 0, don't go into loop, just return -1 
	for (int pos = 0; pos < n && n > 0; pos++)
	{
		if (a[pos] == target)
		{
			return pos; 
		}
	}
	return - 1; 
}
//DONE: find first position of consec string and last pos of consec string 
bool locateSequence(const string a[], int n, string target, int& begin, int& end)
{
	if (n <= 0)
	{
		return false; 
	}
	//through the loop 
	for (int currPos = 0; currPos < n; currPos++)
	{
		//if find target set beginning = current 
		if (a[currPos] == target)
		{
			begin = currPos; 
			end = begin; 
			for (int nextString = begin + 1 ; nextString < n && a[nextString] == target; nextString++)
			{
				end = nextString;
			}
			return true; 
		}	
	}
	return false; 
}
// DONE: returns position of string in array such that it is <=
// every string in array
int locationOfMin(const string a[], int n)
{
	//array has no elements or negative elements
	if (n <= 0)
	{
		return -1; 
	}
	int currMin = 0;
	for (int currPos = 0; currPos < n; currPos++)
	{
		// if we see something smaller than currMin
		if (a[currPos] < a[currMin])
		{
			// save it
			currMin = currPos; 
		}
	} 
	return currMin; 
}
// DONE copy all elements after pos one element to the left 
int moveToEnd(string a[], int n, int pos)
{
	//if elements number negative or position out of scope 
	if (n <= 0 || pos >= n)
	{
		return -1; 
	}

	//save these values to use at the end
	const int originalPos = pos; 
	const string temp = a[originalPos]; 		
	for (int i = pos; i+1 < n; i++)
	{ 
		// cerr << "replace " << a[i] << "with " << a[i+1] << endl;
		a[i] = a[i+1]; //sets current equal to character after it 
	}
 	a[n - 1] = temp;
	return originalPos;  
}

// DONE: move string in pos to first pos in the array 
//return original position of item moved
//we want to shift everything before the original to the left 
int moveToBeginning(string a[], int n, int pos)
{
	//if elements number negative or position out of scope 
	if (n <= 0 || pos >= n)
	{
		return -1;
	}

	const int originalPos = pos; 
	const string temp = a[originalPos];
	for (int i = pos; i >= 0; i--)
	{
		a[i] = a[i - 1]; //sets current equal to character before it 
	}
	a[0] = temp; 
	return originalPos; 
} 
// DONE: if either equal to 0, return 0--the strings are equal all the way 
int locateDifference(const string a1[], int n1, const string a2[], int n2)
{
	int curridx = 0;
	//elements number cannot be negative 
	if (n1 < 0 || n2 < 0)
	{
		return -1; 
	}
	for (; curridx < n1 && curridx < n2; curridx++)
	{
		if (a1[curridx] != a2[curridx])
		{
			return curridx; 
		}
	}
	//should one run out and equal up to there, return smaller of n1/n2
	return curridx; 
}
// DONE:deletes duplicates 
// return number of retained items
int eliminateDups(string a[], int n)
{
	// end of the array
	int end = n;
	int numRetained = 0; 
	int i; 
	//number of elements cannot be negative 
	if (n < 0)
	{
		return -1;
	}
	// for every string
	for (int idx = 0; idx < end;) 
	{
		//if it's in bounds and it's a duplicate 
		if(idx + 1 < end && a[idx] == a[idx + 1]) 
		{
			// remove an element by copying over everything
			for (i = idx; (i + 1) < end; i++)
			{ 
				a[i] = a[i + 1]; 
			}
			end--;
		} 
		else
		{
			idx++; 
			numRetained++;
		}
	}	
	return numRetained;
}

//DONE: if all n2 elements appear in a1, not in necessarily consecutively
bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	int bIndex;
	int sIndex = 0;

	if (n2 == 0)
	{
		return true;
	}

	for (bIndex = 0; bIndex < n1; bIndex++)
	{
		if (sIndex < n2 && a1[bIndex] == a2[sIndex])
		{
			sIndex++; 
		}
	}
    //all elements in a2 appear in a
	if (sIndex == n2)
	{
		return true; 
	}
	// if the complete subsequence wasn't found
	return false; 
}
// DONE 
int makeMerger(const string a1[], int n1, const string a2[],
int n2, string result[], int max)
{
	int idx1 = 0; 
	int idx2 = 0; 

	//if two arrays combined more than max result size 
	if (max < n1 + n2) 
	{
		return -1; 
	}
	//check if both are non decreasing 
	for(int i = 0; i + 1 < n1; i++) {
		if (a1[i] > a1[i + 1]) {
			return -1;
		}
	}
	for(int i = 0; i + 1 < n2; i++) {
		if (a2[i] > a2[i + 1]) {
			return -1;
		}
	}

	for (int idx3 = 0; idx3 < n1+n2; idx3++)
	{
		//if a1 > a2, set position in result array = a2
		if (idx1 < n1 && idx2 < n2 && a1[idx1] >= a2[idx2])
		{
			result[idx3] = a2[idx2];
			idx2++; 
		}
		//if a1 < a2, set next position in result array = a1 
		else if (idx1 < n1 && idx2 < n2 && a2[idx2] > a1[idx1])
		{
			result[idx3] = a1[idx1];
			idx1++;
		} 
		//we ran out of elements for n1
		else if (idx1 == n1)
		{
			result[idx3] = a2[idx2];
			idx2++; 
		}
		//ran out for n2
		else if (idx2 == n2)
		{
			result[idx3] = a1[idx1];
			idx1++; 
		}
	
	}
	//size of new array
	return n1+n2;  
}
// DONE
// int divide(string a[], int n, string divider)
// {
// 	//if negative elements, bad parameter
// 	if (n < 0)
// 	{
// 		return -1; 
// 	}

// 	int count = 0; 
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (a[i] < divider) 
// 		{
// 			moveToBeginning(a, n, i);
// 			count++;
// 		}
// 	}
// 	return count; 
// }

int divide(string array[ ],int n, string divider)
{
	
}


	



