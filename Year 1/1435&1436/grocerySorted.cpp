//********************************************************************
//Name: Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 3 Problem 1
//Date:2/17/2021
//Program description: Gets Data from sales.dat and orginizes and displays them to user.
//*********************************************************************

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
void monAve(double[], const string [], const int[], int);
double yearAve(const double[], int);
void high(const double[], const string[], int);
void low(const double[], const string [], int);
void selectioSortDuo(double[], string[], int);
int findMin(double[], int, int);
void swap(double [], int, int);
void swap(string [], int, int);



int main()
{
    //Checks for sales.dat and closes file.
    ifstream inFile;
    inFile.open("sales.dat");
    if(!inFile){
        inFile.close();
        cout << "You need sales.dat to run program";
        return 0;
    }
    inFile.close();
    
    //initilize Months and days for those months
    int size = 12;
    string names[size] = {"January", "February", "March", "April", "May",
                          "June", "July", "August", "September",
                          "October", "November", "December"};
    int days[size] = {31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31};
    //Will hold averages for each month and the year
    double average[size];
    double yAve;
    
    //Another list of months and averages to be sorted from least to greatist
    string namesSorted[size]= {"January", "February", "March", "April", "May",
                               "June", "July", "August", "September",
                               "October", "November", "December"};
    double averageSorted[size];
    
    //Fills in average array then coppys into sortage average array 
    // *Also Displays average array and names*
    monAve(average, names, days, size);
    for(int i = 0; i < size; i++){
        averageSorted[i] = average[i];
    }
    
    //Sorts averageSorted and namessorted and displays them
    selectioSortDuo(averageSorted, namesSorted, size);
    cout << "\nSorted average for each month:\n";
    for(int i = 0; i < size; i++){
        cout << setw(12) << namesSorted[i] << ": $" << fixed << setprecision(2) << averageSorted[i] << endl;
    }
    
    //Gets yearly average, the highest month and lowest montha and displayes them all
    yAve = yearAve(average, size);
    cout << endl << "The yearly average is: $" << yAve << endl;
    high(average, names, size);
    low(average, names, size);
    
    return 0;
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
// const string MONTH[] Is a list of all the months
// const int DAYS[]     Is a list of all the days in a MONTH
// int size       The lize off all this lists above
//
//*************************************************

void monAve(double average[], const string MONTH[], const int DAYS[], int size){
    ifstream inFile;
    inFile.open("sales.dat");
    double month;
    int day;
    for(int i = 0; i < size; i++){
        month = 0;
        for(int j = 0; j < DAYS[i]; j++){
            inFile >> day;
            month += day;
        }
        average[i] = month/DAYS[i];
    }
    cout << "Average for each month:\n";
    for(int i = 0; i < size; i++){
        cout << setw(12) << MONTH[i] << ": $" << fixed << setprecision(2) << average[i] << endl;
    }
    inFile.close();
}

//*************************************************
// yearAve function
// This function findes the average for the year
// 
// Return Value
// ------------
// double		The avarage sails of the year
//
// Parameters
// ------------
// const double average[]	Is a list that holds  all the average sales for each month
// int size           Holds the size of the array
//
//*************************************************
double yearAve(const double average[], int size){
    double av = 0;
    for(int i = 0; i < size; i++){
        av += average[i];
    }
    return av = av/size;
}

//*************************************************
// high function
// This function findes Highest average from the months
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double average[]		Is a list that holds  all the average sales for each month
// const string MONTH[] Is a list of all the months
// int size       Holds size of the arrays
//
//*************************************************
void high(const double average[], const string MONTH[], int size){
    int m = 0;
    for(int i = 1; i < size; i ++){
        if(average[m ]< average[i]){
            m = i;
        }
    }
    cout << "The highest month was " << MONTH[m] << " at $" << average[m] << endl;

}

//*************************************************
// low function
// This function finds the lowest average from the months
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double average[]		Is a list that holds  all the average sales for each month
// const string MONTH[] Is a list of all the months
// int size       Holds size of the arrays
//
//*************************************************
void low(const double average[], const string MONTH[], int size){
    int m = 0;
    for(int i = 1; i < size; i ++){
        if(average[m]> average[i]){
            m = i;
        }
    }
    cout << "The lowest month was " << MONTH[m] << " at $" << average[m] << endl;

}

//*************************************************
// selectioSortDuo function
// This function find sorts sortedAverage and Sorted Names from least to greatist
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double Ave[]		    Is a list that holds  all the average sales for each month
// const string Name[]  Is a list of all the months
// int size       Holds size of the arrays
//
//*************************************************
void selectioSortDuo(double Ave [], string Name[], int size){
    for(int i = 0; i < size; i++){
        int unsortedMin = findMin(Ave, size, i);
        swap(Ave, i, unsortedMin);
        swap(Name, i, unsortedMin);
    }
}

//*************************************************
// findMin function
// This function finds the minimum value from the unsorted part of the array
// 
// Return Value
// ------------
// int the index of the smallest value
//
// Parameters
// ------------
// double Ave[]		    Is a list that holds  all the average sales for each month
// const int size       Holds size of the arrays
// int int              The first index of the unsorted array
//
//*************************************************
int findMin(double Ave[],int size,int i){
    int small = i;
    for(int j = i+1; j<size; j++){
        if(Ave[j]<Ave[small]){
            small = j;
        }
    }
    return small;
}
//*************************************************
// swap function
// This function swaps two values in an array
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// double Ave[]		    Is a list that holds  all the average sales for each month
// int a                Holds the first index
// int b                Holds the second index
//
//*************************************************
void swap(double Ave[], int a, int b){
    int temp = Ave[a];
    Ave[a] = Ave[b];
    Ave[b] = temp;
}
//*************************************************
// swap function
// This function swaps two values in an array
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// string Name[]		Is a list that holds all the months in a year
// int a                Holds the first index
// int b                Holds the second index
//
//*************************************************
void swap(string Name [], int a, int b){
    string temp = Name[a];
    Name[a] = Name[b];
    Name[b] = temp;
}
