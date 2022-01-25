//********************************************************************
// Name: Kevin White
// Class: COSC 1435 Fall 20
// Instructor: Marwa Hassan
// Assignment 6 Problem 1
// Date: 10/16/2020
// Program description: User enters a number and makes a hailstone sequence bassed off of the number
//*********************************************************************
#include <iostream>
#include<math.h>
using namespace std;

int main ()
{
    int num;
    cout << "Please enter a positive integer: ";
    cin >> num;
    while(num < 1){
        cout << "Invalid! Please enter a positive integer: ";
        cin >> num;
    }
    
    
    do{
        cout << num << " ";
        if((num % 2 == 1) && (num != 1)){
            num = num * 3 + 1;
        }
        else if((num % 2 == 0) && (num != 1)){
            num = num/2;
        }
    }while(num != 1);
    cout << 1;
}
