// This program demonstrates the use of dynamic arrays

// Kevin White

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float *monthSales = nullptr;	// a pointer used to point to an array
	                                // holding monthly sales 

	float total = 0;	// total of all sales
	float average;		// average of monthly sales
	int numOfSales;		// number of sales to be processed 
	int count;			// loop counter

	cout << fixed << showpoint << setprecision(2);

	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;
	
	// Fill in the code to validate the size. If 0 or a negative number was entered, 
	// allow the user to re-enter a valid size
	while(numOfSales <= 0){
	    cout << "Number of months must be more than 0 \nTry Again: ";
	    cin >> numOfSales;
	}

	// Fill in the code to allocate memory for the array pointed to by
	// monthSales.
	monthSales = new float [numOfSales];

	cout << "Enter the sales below\n";

	for (count = 0; count < numOfSales; count++)
	{
		cout << "Sales for Month number	"
		     << count + 1
		     << ": $";

		// Fill in code to bring sales into an element of the array
		cin >> monthSales[count];
	}

	for (count = 0; count < numOfSales; count++)
	{
		//fill in the code to calculate the total of all sales
		total += monthSales[count];
	}

	average = total/numOfSales;

	cout << "Average Monthly sale is $" << average << endl;

	// Fill in the code to deallocate memory assigned to the array.
	delete [] monthSales;

	return 0;
}