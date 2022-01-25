//*******************************************************************
//Name: Kevin White
//Class: COSC 1435 Fall 20
//Instructor: Marwa Hassan
//Lab 5 Question 12 (Write the number of the question)
//Date: 9/16/2020
//Program description: Takes feet and makes it into Centimeters
//*******************************************************************

#include <iostream>
using namespace std;

int main()
{
    float feet;
	float centi;
	cout << endl;
	cout << "Enter a value in feet: ";
	cin >> feet;
	centi = feet * 30.48;
	cout << feet << " feet is the same as " << centi << " centimeters" << endl << endl;
	return 0;
}