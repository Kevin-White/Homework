// This program has the user input a number n and then finds the
// mean of the first n positive integers

// Kevin White

#include <iostream>
using namespace std;

void firstToLast (int s, int b);

int
main ()
{
  int sValue, bValue;		// value is some positive number n


  cout << "Please enter a positive integer" << endl;
  cin >> sValue;
  cout << "Please enter a positive integer larger than the first" << endl;
  cin >> bValue;
  while ((sValue <= 0) || (bValue < sValue))
    {
      cout << "input not accepted, try again.\n\n";
      cout << "Please enter a positive integer" << endl;
      cin >> sValue;
      cout << "Please enter a positive integer larger than the first" << endl;
      cin >> bValue;
    }
firstToLast(sValue, bValue);
return 0;
}

void
firstToLast (int s, int b)
{
  int total = 0;		// total holds the sum of the first n positive numbers 
  int number;			// the amount of numbers
  float mean;			// the average of the first n positive numbers
  int count = 0;

  for (number = s; number <= b; number++)
    {
      total = total + number;
      count++;
    }				// curly braces are optional since there is only one statement

  mean = static_cast < float >(total) / count;	// note the use of the typecast
  // operator here 
  cout << "The mean average of values between " << s << " and " << b
    << " positive integers is " << mean << endl;


}

