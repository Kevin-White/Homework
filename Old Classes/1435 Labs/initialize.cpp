// This program tests whether or not an initialized value
// is equal to a value entered by the user

// Kevin White

#include <iostream>
using namespace std;

int main()
{
	int num1,	// num1 is not initialized
	num2;	// num2 is not initialized 

	cout << "Please enter an integer for num1: " << endl;
	cin >> num1;
	//The user is now going to enter the value for the second int as well
	cout << "Please enter an integer for num2: " << endl;
	cin >> num2;

	cout << "num1 = " << num1 << " and num2 = " << num2 << endl;

	// you need == not just = to compare
	if (num1 == num2)
		cout << "The values are the same." << endl;

	else
		cout << "The values are not the same" << endl;

	return 0;
}