//********************************************************************
//Name:Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 6
//Date: 11/4/2021
//Program description: Shows off Size function for queueType.h
//********************************************************************

#include <iostream>
#include "queueType.h"
using namespace std;

int main(){
    queueType<string> brothers;
    brothers.addQueue("Kevin");
    brothers.addQueue("Erik");
    brothers.addQueue("Andrew");
    brothers.addQueue("Ryan");

    queueType<string> brothersCopy = brothers;


    cout << "Number of elements in brothers Queue: " << brothers.size() << endl;

    queueType<string> parents;
    parents.addQueue("Iwona");
    parents.addQueue("Kirk");

    cout << "Number of elements in parents Queue: " << parents.size();

}