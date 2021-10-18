//********************************************************************
//Name: Kevin White
//Class: COSC 1435 F20
//Instructor: Marwa Hassan
//Assignment 7 Problem 1
//Date: 11/2/2020
//Program description: Finds number of steps in a given monthl
//*********************************************************************


#include <iostream>
#include<math.h>
#include <fstream>
using namespace std;
void monthAve(int, double);
int month(int, double);

int main ()
{
    ifstream inFile;
    inFile.open("steps.dat");
    double sum = 0;
    int step;
    cout << "Month\tAverage number of steps" << endl
    << "------------------------------------" << endl;
    for(int i = 1; i <= 365; i++){
        inFile >> step;
        sum += step;
        sum = month(i, sum);
        
    }
}
//*************************************************
// month function
// Uses switch statement to find month
//
// Return Value
// ------------
// Resets sum back to 0 after every month
//
// Parameters
// ------------
// int i Day of the year
// doulbe sum Sum of all steps that month
//*************************************************
int month(int i, double sum){
switch(i){
            case 31:
            cout << "January\t\t";
                monthAve(i, sum);
                return 0;
                break;
            case 59: 
            cout << "Febuary\t\t";
                monthAve(i-31, sum);
                return 0;
                break;
            case 90:
            cout << "March\t\t";
                monthAve(i-59, sum);
                return 0;
                break;
            case 120:
            cout << "April\t\t";
                monthAve(i-90, sum);
                return 0;
                break;
            case 151:
            cout << "May\t\t";
                monthAve(i-120, sum);
                return 0;
                break;
            case 181:
            cout << "June\t\t";
                monthAve(i-151, sum);
                return 0;
                break;
            case 212:
            cout << "July\t\t";
                monthAve(i-181, sum);
                return 0;
                break;
            case 243:
            cout << "Augest\t\t";
                monthAve(i-212, sum);
                return 0;
                break;
            case 273:
            cout << "September\t";
                monthAve(i-243, sum);
                return 0;
                break;
            case 304:
            cout << "October\t\t";
                monthAve(i-273, sum);
                return 0;
                break;
            case 334:
            cout << "November\t";
                monthAve(i-304, sum);
                return 0;
                break;
            case 365:
            cout << "December\t";
                monthAve(i-334, sum);
                return 0;
                break;
            default:
                //do nothing;
                return sum;
                break;
        }
}
//*************************************************
// monthAve function
// Prints average steps for the month
//
// Return Value
// ------------
// NONE
//
// Parameters
// ------------
// int days Day of the year
// double sum Sum of all steps that month
//*************************************************
void monthAve(int days, double sum){
    cout << sum/days << endl;
}

