//********************************************************************
//Name: Kevin White
//Class: COSC 1435 Spring 21
//Instructor: Marwa Hassan
//Assignment 1 Problem 1
//Date: 1/30/2021
//Program description: Lists through sales throughout the year and gives gives information about those sales.
//*********************************************************************

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
void monAve(double[]);
double yearAve(const double[]);
void high(double[]);
void low(double[]);
const string MONTH[12] = {"January", "February", "March", "April", "May",
                                  "June", "July", "August", "September",
                                  "October", "November", "December"};
const int DAYS[12] = {31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31};


int main()
{
    double average[12];
    double yAve;
    monAve(average);
    yAve = yearAve(average);
    cout << endl << "The yearly average is: " << yAve << endl;
    high(average);
    low(average);
    
    
}
//*************************************************
// monAve function
// This function findes the average for each month
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double average[]		Is a list that will soon hold all the average sales for each month
//
//*************************************************

void monAve(double average[]){
    ifstream inFile;
    inFile.open("sales.dat");
    double month;
    int day;
    for(int i = 0; i < 12; i++){
        month = 0;
        for(int j = 0; j < DAYS[i]; j++){
            inFile >> day;
            month += day;
        }
        average[i] = month/DAYS[i];
    }
    cout << "Average for each month:\n";
    for(int i = 0; i < 12; i++){
        cout << setw(12) << MONTH[i] << ": " << fixed << setprecision(2) << average[i] << endl;
    }
}

//*************************************************
// yearAve function
// This function findes the average for each month
// 
// Return Value
// ------------
// double		The avarage sails of each month for the year
//
// Parameters
// ------------
// double average[]		Is a list that holds  all the average sales for each month
//
//*************************************************
double yearAve(const double average[]){
    double av = 0;
    for(int i = 0; i < 12; i++){
        av += average[i];
    }
    return av = av/12;
}

//*************************************************
// high function
// This function findes the average for each month
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double average[]		Is a list that holds  all the average sales for each month
//
//*************************************************
void high(double average[]){
    int m = 0;
    for(int i = 1; i < 12; i ++){
        if(average[m ]< average[i]){
            m = i;
        }
    }
    cout << "The highest month was " << MONTH[m] << " at " << average[m] << endl;

}

//*************************************************
// low function
// This function findes the average for each month
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double average[]		Is a list that holds  all the average sales for each month
//
//*************************************************
void low(double average[]){
    int m = 0;
    for(int i = 1; i < 12; i ++){
        if(average[m ]> average[i]){
            m = i;
        }
    }
    cout << "The lowest month was " << MONTH[m] << " at " << average[m] << endl;

}


