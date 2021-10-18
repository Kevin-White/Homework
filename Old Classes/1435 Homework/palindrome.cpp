//********************************************************************
//Name:Kevin White
//Class: COSC 1435 Fall 20
//Instructor: Marwa Hassan
//Assignment x Problem x
//Date:10/6/2020
//Program description: Checks if word is a palindrome
//*********************************************************************
#include <stdio.h>
#include <iostream>

using namespace std;

int
main (){
  char one, two, three, four, five;
  cout << "Please enter 5 letters\n";
  cin >> one >> two >> three >> four >> five;
  cout << one << two << three << four << five << " ";
  if((one == five) && (two == four)){
        cout << "is a palindrome!";   
  }
  else{
      cout << "is NOT a palindrome!";
  }
}
