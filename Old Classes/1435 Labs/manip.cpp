#include <iostream>
#include<iomanip>
using namespace std; 
int main()
{
	int first = 2897,
		second = 5,
		third = 837,
		fourth = 34,
		fifth = 8,
		sixth = 1524;
		
		cout << setw(4) << first << " " << setw(4) << second << " "
		<< setw(4) << third << endl;
		cout << setw(4) << fourth << " " << setw(4) << fifth << " "
		<< setw(4) << sixth << endl;
		
		const float PI = 3.14159;
		cout << "Pi = " << setprecision(6) << PI << endl;
		cout << "Pi = " << setprecision(5) << PI << endl;
		cout << "Pi = " << setprecision(4) << PI << endl;
		cout << "Pi = " << setprecision(3) << PI << endl;
		cout << "Pi = " << setprecision(2) << PI << endl;
		cout << "Pi = " << setprecision(1) << PI << endl;
		
		double month1 = 1234567.89,
			   month2 = 2345.67,
			   month3 = 3456.78;
		
		cout << setprecision(6);
		cout << "The first month’s sales = $" << month1 << endl;
		cout << "The second month’s sales = $" << month2 << endl;
		cout << "The third month’s sales = $" << month3 << endl;
		
		cout << setprecision(2) << fixed;
		cout << "The first month's sales = $" << month1 << endl;
		
		float grade1 = 80.0,
		grade2 = 85.0,
		grade3 = 90.0,
		avg;
		
		avg = (grade1 + grade2 + grade3) / 3;
		cout << "The average grade is " << avg << endl;
		cout << setprecision(4) << showpoint;
		cout << "The average grade is " << avg << endl;
		cout << fixed << setprecision(4) << showpoint;
		cout << "The average grade is " << avg << endl;
		
		string lname1 = "Date",
		lname2 = "Reckonwith",
		fname1 = "Julian",
		fname2 = "Amanda";
		
		cout << left << setw(12) << lname1 << " " << setw(12) << fname1 << endl 
		<< setw(12) << lname2 << " " << setw(12) << fname2 << endl;



    return 0;
}