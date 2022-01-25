#include <iostream>
#include <cmath>     // For sqrt and pow functions
using namespace std;
 
// Function average prototype
double average(double, double, double);
 
// Function stdev prototype
//-----Add the prototype for standard deviation function here
double stdev(double, double, double, double);
 
int main()
{
	double d1, d2, d3;
	double avg, dev;
	char again;

	do
	{
		cout << "Enter 3 doubles: ";
		cin >> d1 >> d2 >> d3;
		avg = average(d1, d2, d3);     
		cout << "The average is " << avg << endl; 
		
		//*************************************************************
		// Add the calling statement and cout for standard deviation here
		//*************************************************************
		dev = stdev(d1, d2, d3, avg);
		cout << "The deviation is " << dev << endl;
		
		cout<<"\nDo you wish to enter another set of numbers?(Y|N) ";
		cin >> again;
	} while(again == 'Y' || again == 'y');

	cout << "Goodbye\n";
	return 0;
}
//*************************************************
// average function
// Purpose:  Compute the average of three doubles
//
// Return Value
// ------------
// double            average of the three numbers
//
// Parameters
// ------------
// double num1             first number
// double num2             second number
// double num2             second number
//*************************************************
double average(double num1, double num2, double num3)
{
     double avg;
     avg = (num1 + num2 + num3) / 3;
     return avg;  //or just return (num1 + num2 + num3) / 3;
}
 
//*************************************************************
// Add the body for standard deviation function here
//*************************************************************
double stdev(double num1, double num2, double num3, double a){
    double sum;
    double dev;
    num1 = pow(num1-a, 2);
    num2 = pow(num2-a, 2);
    num3 = pow(num3-a, 2);
    sum = num1 + num2 + num3;
    dev = sqrt(sum/2);
    return dev;
}

