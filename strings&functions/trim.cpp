
#include <string>
#include <assert.h>
using namespace std; 

void trim(string& str);

int main () {
      string s1 = "   test   "; 
      string s2 = "   ";
      string s3 = " test this ";
      
      trim(s1);
      trim(s2);
      trim(s3);
      
      assert(s1 == "test");
      assert(s2 == "");
      assert(s3 == "test this");
  }


//given position, shifts everything after to the left by one 
void shiftLeft(string& str, int pos){
      for (int i = pos; i+1 < str.size();i++){
            str[pos] = str[pos+1]; 
      }
      str[str.size()] = '\0';
}

//takes in string by reference and removes trailing and leading whitespace 
void trim(string& str){
      //loop through string
      for (int i = 0; i < str.size(); i++){
            if (str[i] == ' ')
                  shiftLeft(str, i);
      }
}