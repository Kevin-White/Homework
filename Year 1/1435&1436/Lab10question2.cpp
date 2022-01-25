// This program has the user input a number n and then finds the
// mean of the first n positive integers

// Kevin White

#include <iostream>
using namespace std;

int main()
{
	int sValue, bValue;		// value is some positive number n
	int total = 0;	// total holds the sum of the first n positive numbers 
	int number;		// the amount of numbers
	float mean;		// the average of the first n positive numbers
	int count = 0;

	cout << "Please enter a positive integer" << endl;
	cin >> sValue;
	cout << "Please enter a positive integer larger than the first" << endl;
	cin >> bValue;

	if ((sValue > 0) && (bValue > sValue))
	{
		for (number = sValue; number <= bValue; number++)
		{
			total = total + number;
			count ++;
		}	// curly braces are optional since there is only one statement

		mean = static_cast<float>(total) / count;	// note the use of the typecast
													// operator here 
		cout << "The mean average of values between " << sValue << " and " << bValue
			 << " positive integers is " << mean << endl;
	}

	else
		cout << "Invalid input - integer must be positive" << endl;

	return 0;
}
