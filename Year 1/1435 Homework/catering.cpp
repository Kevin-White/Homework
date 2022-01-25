//********************************************************************
//Name: Kevin White
//Class: COSC 1435 Fall 20
//Instructor: Marwa Hassan
//Assignment x Problem x
//Date:9/28/2020
//Program description: Finds the total price of adults and children plus tax that 
//                     attended the party
//*********************************************************************
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	//adding all the var's
    int aPrice = 10;
    int cPrice = 6;
    int numC, numA;
    double total;

//Getting the number of adults and calculating the price of adults to add to total
    cout << "Enter the number of adults that attended the party:" << endl;
    cin >> numA;
    total = numA * aPrice;

//Getting the number of children and calculating the price of children to add to total
    cout << "Enter the number of children that attended the party:" << endl;
    cin >> numC;
    total += (numC * cPrice);

//adding Tax to the total and printing total with at least 2 decimal places.
    total *= 1.0825;
    cout << setprecision(2) << fixed;
    cout << "The cost for everyone to attend will be $" << total << endl;
    return 0;
}

