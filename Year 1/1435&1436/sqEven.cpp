//********************************************************************
//Name: Kevin White
//Class: COSC 1435 F20
//Instructor: Marwa Hassan
//Assignment 7 Problem 2
//Date: 11/2/2020
//Program description: Displays the sum of all even squares between two even values
//*********************************************************************


#include <iostream>
#include<math.h>
#include <fstream>
using namespace std;
bool checkPositive(int, int);
int evenSquares(int, int);

int main ()
{
   int x, y, sum;
   cout << "Enter two numbers" << endl;
   cin >> x >> y;
   while(!checkPositive(x,y)){
    cout << "input not valid try again" << endl;  
    cout << "Enter two numbers" << endl;
   cin >> x >> y;
   }
   sum = evenSquares(x,y);
   cout << sum;
   
}
//*************************************************
// evenSquares function
// Add up sum of all even squares
//
// Return Value
// ------------
// int sum of even squares
//
// Parameters
// ------------
// int a first number
// int b second number
//*************************************************
int evenSquares(int a, int b){
    int sum = 0, s = 0, sq = 0;;
    if(a > b){
        s = a;
        a = b;
        b = s;
    }
    
    for(int i = a; i <= b; i++){
        if(i%2 == 0){
        sq = i*i;
        sum += sq;
        }
    }
    return sum;
}
//*************************************************
// checkPositive function
// Returns wether both ints are positive
//
// Return Value
// ------------
// Bool based on if ints are positive
//
// Parameters
// ------------
// int a first number
// int b second number
//*************************************************
bool checkPositive(int a,int b){
    if(a > 0 && b > 0){
        return true;
    }else{
     return false;   
    }
}
    

