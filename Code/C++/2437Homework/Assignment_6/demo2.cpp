//********************************************************************
//Name:Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 6
//Date: 11/4/2021
//Program description: Shows off Size function for linkedQueue.h
//********************************************************************

#include <iostream>
#include "linkedQueue.h"
using namespace std;

int main(){
    LinkedQueue<string> brothers;
    brothers.addQueue("Kevin");
    brothers.addQueue("Erik");
    brothers.addQueue("Andrew");
    brothers.addQueue("Ryan");

    cout << "Number of elements in brothers Queue: " << brothers.size() << endl;

    LinkedQueue<string> parents;
    parents.addQueue("Iwona");
    parents.addQueue("Kirk");

    cout << "Number of elements in parents Queue: " << parents.size();

}