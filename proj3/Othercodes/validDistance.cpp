

#include <iostream> 
#include <cctype>
using namespace std; 
#include <assert.h>
	// these need to be checked for EVERY command 
	//make sure for currRow and currCol to pass by reference 
	bool validDistance (int currRow, int currCol, int dir, int distance)
	{
		if (distance >= 0) 
		{
			//if moving rightward, we don't want last column beyond 30
			if (dir == 0 && (currCol + distance) < 30)
			{
				return true; 
			}
			//if moving down vertically, we don't want last row beyond 20 
			else if (dir == 1 && (currRow + distance) < 20)
			{
				return true; 
			}
			else 
			{
				return false; 
			}
		}
		else if (distance < 0) 
		{
			distance *= -1; 
				//moving left, we don't want to move beyond column 1 
				if (dir == 0 && !((currCol - distance) < 1))
				{
					return true; 
				}
				//moving up, we don't want to move beyond row 1 
				else if (dir == 1 && !((currRow - distance) < 1))
				{
					return true; 
				}
				else 
				{
					return false; 
				}
		}
		else 
		{
			return false; 
		}
	}

	int main () 
	{
		//Top left corner 
		//HORIZ moving left out of bounds 
		assert (!(validDistance(1, 1, 0, -1))); 
		//VERT moving up out of bounds 
		assert(!(validDistance(1, 1, 1, -1))); 

		//Top right corner 
		//HORIZ moving right out of bounds 
		assert (!(validDistance (1, 30, 0, 1)));
		//VERT moving up out of bounds 
		assert (!(validDistance(1, 30, 1, -1)));

		//Bottom left 
		//HORIZ moving left out of bounds
		assert (!(validDistance (20, 1, 0, -1)));
		//VERT moving down out ofbounds 
		assert (!(validDistance (20, 1, 1, 1)));

		//Bottom right
		//HORIZ moving right out of bounds 
		assert (!(validDistance(20, 30, 0, 1)));
		assert (!(validDistance (20, 30, 1, 1)));

		

		cerr << "wow passed tests" << endl;
	}