//*******************************************************************
//Name: Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 5
//Date: 10/22/2021
//Program description: Test the new operator== added to myStack.h
//*******************************************************************
#include <iostream>
#include "myStack.h"
using namespace std;

int main(){
    stackType<int> test1, test2, test3;

    for(int i = 0; i < 10; i++){
        test1.push(i);
        test2.push(i);
        test3.push(i+1);
    }
    
    if(test1 == test2){
        cout << "Test 1 is equal to Test 2" << endl;
    }

    if(!(test1 == test3)){
        cout << "Test 1 is NOT equal to Test 3" << endl;
    }

}