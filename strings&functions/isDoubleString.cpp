#include <iostream>
#include <cctype>
#include <cassert>
#include <string>
using namespace std; 

bool isDoubleString(string s);
void trim (string& s); 


int main() {

	assert(  isDoubleString("1.23")); // True
	assert(  isDoubleString("1")); // True
	assert(  isDoubleString("  1.23  ")); // True
	assert(  isDoubleString(".23")); // True
	assert(! isDoubleString("  1.  23  ")); // False
	assert(! isDoubleString("1.2.3.4")); // False
	assert(! isDoubleString("I IZ DUBLE :DDD")); // False
	assert(! isDoubleString("1a.23")); // False
	assert(! isDoubleString("a1.23")); // False
	assert(! isDoubleString("")); // False
  
      cerr << "[!] ALL TESTS PASSED!" << endl;
}




void trim (string& s) {
      if (s.empty()) {
          return;
      }
  
      int firstChar = 0,
          lastChar = s.length() - 1;
  
      // Move the firstChar index inwards to find the first non-space
      // character, and then the lastChar index inwards to find the last
      // non-space character
      while (s[firstChar] == ' ' && firstChar < s.length()) {
          firstChar++;
      }
      while (s[lastChar] == ' ' && lastChar > 0) {
          lastChar--;
      }
  
      // If they passed each other, then there were all spaces
      if (firstChar > lastChar) {
          s = "";
  
      // Otherwise, we can substr to get the right result
      // Note the +1 at the length because lastChar finds the
      // index of the last char, which would otherwise not include
      // the last char from the call to substr
      } else {
          s = s.substr(firstChar, lastChar - firstChar + 1);
      }
  }

bool isDoubleString(string s){
	trim (s); 
	for (int i = 0; i < s.length(); i++){
		if (!((int)s[i] > 47 && (int) s[i] < 58)){
      cout << "not read as number" << endl;
		  if (s[i] != '.')
      return false; 
		}
	}
	return true; 
}








