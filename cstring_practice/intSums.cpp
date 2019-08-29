

  #include <iostream>
  #include <string>
  #include <cstring>
  #include <cassert>
  using namespace std;
  
  const int MAX_INTS = 3;
//takes in 2D array, sum of rows, places them in corresponding column of result 
void intSums (int a[][MAX_INTS], int result[], int n){
	//loop through rows 
	for (int row = 0; row < n; row++){
		int arraySum = 0; 
		for (int column = 0; column < MAX_INTS; column++){
			arraySum += a[row][column]; 
		}
	result[row] = arraySum;
	}
}




 int main () {
      int a[][MAX_INTS] = {
          {1, 2, 3},
          {0, 0, 0},
          {5, -5, 1}
      };
      int result[MAX_INTS];
  
      intSums(a, result, MAX_INTS);
  
      assert(result[0] == 6 && result[1] == 0 && result[2] == 1);
  
      cout << "[!] ALL TEST(S) PASSED" << endl;
  }