//********************************************************************
//Name: Kevin
//Class: COSC 1435 Fall-20
//Instructor: Marwa Hassan
//Assignment 9 Problem 1
//Date: 11/17/2020
//Program description: Info about steps for the month
//*********************************************************************
#include <iostream>
#include<math.h>
#include <fstream>
using namespace std;
void monthAve(double []);
double yearAve(double []);
void highMon(double []);
void lowMon(double []);
bool moreThan(double);
const string MONTHS[12] = { "January", "February", "March", "April", "May",
 "June", "July", "August", "September",
 "October", "November", "December" };
const int DAYS[12] = { 31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31 };
int main ()
{
    double ya;
    double monthSteps[12];
    monthAve(monthSteps);
    ya = yearAve(monthSteps);
    cout << "Average steps for the year: " << ya << endl;
    highMon(monthSteps);
    lowMon(monthSteps);
    cout << "These months have an average higher than 6450" << endl
    << "------------------------------------" << endl;
    for(int i = 0; i < 12; i++){
        if(moreThan(monthSteps[i])){
            cout << MONTHS[i] << ": " << monthSteps[i] << endl;
        }
    }
    
}
//*************************************************
// monthAve function
// This function finds the average steps for every month
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double monthSteps[]   Average steps per month
//*************************************************
void monthAve(double monthSteps[]){
    fstream inFile;
    inFile.open("steps.dat");
    int sum = 0;
    int monthCount = 0;
    int dayCount = 0;
    int hold;
    cout << "Month\tAverage number of steps" << endl
        << "------------------------------------" << endl;
        for(int i = 0; i <= 365; i++){
            inFile >> hold;
            sum += hold;
            dayCount++;
            if(dayCount == DAYS[monthCount]){
                monthSteps[monthCount] = sum;
                monthSteps[monthCount] /= DAYS[monthCount];
                monthCount++;
                dayCount = 0;
                sum =0;
            }
        }
        for(int i = 0; i < 12; i++){
            cout << MONTHS[i] << ": " << monthSteps[i] << endl;
        }
        cout << endl << endl;

}
//*************************************************
// yearAve function
// This function finds the average steps for the year
//
// Return Value
// ------------
// doulbe Yearly Average
//
// Parameters
// ------------
// double monthSteps[]   Average steps per month
//*************************************************
double yearAve(double monthSteps[]){
    double ya = 0;
    for(int i = 0; i < 12; i++){
        ya += monthSteps[i];
    }
    ya /= 12;
    return ya;
}

//*************************************************
// highMon function
// This function finds highest monthly average
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double monthSteps[]   Average steps per month
//*************************************************
void highMon(double monthSteps[]){
    int rem = 0;
    double high = monthSteps[0];
    for(int i = 1; i < 12; i++){
        if(monthSteps[i] > high){
            high = monthSteps[i];
            rem = i;
        }
    }
    cout << "You had the highest number of average steps in " << MONTHS[rem] << ": " << monthSteps[rem] << endl;
}

//*************************************************
// lowMon function
// This function finds lowest monthly average
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double monthSteps[]   Average steps per month
//*************************************************
void lowMon(double monthSteps[]){
    int rem = 0;
    double low = monthSteps[0];
    for(int i = 1; i < 12; i++){
        if(monthSteps[i] < low){
            low = monthSteps[i];
            rem = i;
        }
    }
    cout << "You had the lowest number of average steps in " << MONTHS[rem] << ": " << monthSteps[rem];
}
//*************************************************
// moreThan function
// This function checks if monthyl Average is above 6450
//
// Return Value
// ------------
// bool true/false
//
// Parameters
// ------------
// double steps the number of steps for a month
//*************************************************
bool moreThan(double steps){
    if(steps >= 6450){
        return true;
    }
    return false;
}