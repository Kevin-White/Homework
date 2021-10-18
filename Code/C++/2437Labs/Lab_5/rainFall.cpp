// COSC2437 
#include<iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

// Constant for the number of months
const int NUM_MONTHS = 12;


int main()
{
	// Array to hold the rainfall data
    LinkedList<double> rainFall;

	// Get the rainfall for each month.
	for (int month = 0; month < NUM_MONTHS; month++)
	{
        double monthRain;
		// Get this month's rainfall.
		cout << "Enter the rainfall (in inches) for month #";
		cout << (month + 1) << ": ";
		cin >> monthRain;
        rainFall.appendNode(monthRain);
      
		// Validate the value entered.
		while (rainFall.getValueAt(month) < 0)
		{  
			cout << "Rainfall must be 0 or more.\n"
				 << "Please re-enter: ";
			cin >> monthRain;
            rainFall.appendNode(monthRain);
		}
	}
   
	// Set the numeric output formatting.
	cout << fixed << showpoint << setprecision(2) << endl;
   
	// Display the total rainfall.
	cout << "The total rainfall for the year is ";
	cout << rainFall.getTotal()
	     << " inches." << endl;
   
	// Display the average rainfall.
	cout << "The average rainfall for the year is ";
	cout << rainFall.getAverage()
	     << " inches." << endl;

	// Now display the largest & smallest amounts.
	// The subscript variable will be passed by reference
	// the the getLargest and getSmallets functions.
	int subScript;

	// Display the largest amount of rainfall.
	cout << "The largest amount of rainfall was ";
	cout << rainFall.getLargest()
	     << " inches in month ";
	cout << (rainFall.getLargestPosition() + 1) << "." << endl;

	// Display the smallest amount of rainfall.
	cout << "The smallest amount of rainfall was ";
	cout << rainFall.getSmallest()
	     << " inches in month ";
	cout << (rainFall.getSmallestPosition() + 1) << "." << endl << endl;

	return 0;
}
