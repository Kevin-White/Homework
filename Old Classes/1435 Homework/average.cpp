//********************************************************************
// Name: Kevin White
// Class: COSC 1435 Fall 20
// Instructor: Marwa Hassan
// Assignment 6 Problem 2
// Date: 10/16/2020
// User enters 2 numbers and finds the sum of all the numbers in between as well as the average.
//*********************************************************************
#include <iostream>
#include<math.h>
using namespace std;

int main (){
    int num1, num2, swap;
    double average, sum = 0;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    
    if(num1 > num2){
        swap = num1;
        num1 = num2;
        num2 = swap;
    }
    
    cout << "Sum = ";
    int i = 0;
    
    for(i = num1; i <= num2; i++){
        cout << i << " + ";
        sum += i;
    }
    
    cout << "= " << sum;
    cout << endl;
    average = (num1 + num2)/2.0;
    cout << "Average = " << average;
}

