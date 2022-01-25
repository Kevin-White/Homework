// This program finds the average time spent programming by a student
// each day over a three day period.

// Kevin White

#include <iostream>
using namespace std;

int main()
{
	int numStudents, numDays;
	float numHours, total, average;
	int student, day = 0;	// These are the counters for the loops

	cout << "This program will find the average number of hours a day"
		 << " that a student spent programming over a period of time\n\n";
	cout << "How many students are there ?" << endl << endl;
	cin >> numStudents;
	cout << "How many days did they work?" << endl << endl;
	cin >> numDays;

	for (student = 1; student <= numStudents; student++)	
	{									// This loop steps through each student
		total = 0;

		for (day = 1; day <= numDays; day++)	// This loop steps through each day
		{								// for each student
			cout << "Please enter the number of hours worked by student "
				 << student << " on day " << day << "." << endl;
			cin >> numHours;

			total = total + numHours;
		}

		average = total / numDays;

		cout << endl;
		cout << "The average number of hours per day spent programming by "
			 << "student " << student << " is " << average
			 << endl << endl << endl;
	}

	return 0;
}
