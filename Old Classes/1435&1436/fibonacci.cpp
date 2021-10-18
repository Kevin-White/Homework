/******************************************************************************

fibonacci team coding project;

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int
main ()
{
  int num1, num2, sumNum, choice, count;
  num1 = 0;
  num2 = 1;
  cout << "How many fibonacci numbers would you like?\n";
  cin >> choice;
  if (choice == 1)
    {
      cout << num1;
    }
  else if (choice == 2)
    {
      cout << num1 << " " << num2;
    }
  else
    {
      cout << num1 << " " << num2;
      choice = choice - 2;
      while (choice > 0)
	{
	  sumNum = num1 + num2;
	  cout << " " << sumNum;
	  num1 = num2;
	  num2 = sumNum;
	  choice--;

	}
    }
}
