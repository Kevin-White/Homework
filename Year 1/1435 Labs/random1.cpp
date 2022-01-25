// This program demonstrates random numbers.
#include <iostream>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function
using namespace std;

int main()
{
	int maxV, minV, r;
	
   // Get the min and max from user.
   cout << "Generate random integer in a specific range:"
   << endl << " --------------------------------------------------" << endl;
   
   cout << "Enter the minimum value: ";
   cin >> minV;
   cout << "Enter the maximum value: ";
   cin >> maxV;
   unsigned seed = time(0);
   srand(seed);
   
   r = (rand() % (minV - maxV + 1)) + minV;
	
	// Display one random numbers.
	cout << "The random number between " << minV << " and " << maxV
	<< " is: " << r << endl;
 
   return 0;
}