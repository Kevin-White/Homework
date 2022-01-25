//********************************************************************
//Name:Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 9 Problem 1
//Date: 4/30/2021
//Program description: Program that makes and displays functions in LinkedList class
//*********************************************************************



#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);
    
    list.displayList();
    cout << endl << "list length: " << list.length() << endl << endl;
   
    list.insertNode(5);
    list.insertNode(15);
    list.insertNode(25);
   
    list.displayList();
    cout << endl << "list length: " << list.length() << endl << endl;
    
    list.deleteNode(10);
    list.deleteNode(20);
    list.deleteNode(30);
    
    list.displayList();
    cout << endl << "list length: " << list.length() << endl << endl;
    
    list.displayList();
    cout << endl;
    cout << "index of 15: " << list.findOrder(15) << endl;
    cout << "index of 100: " << list.findOrder(100) << endl << endl;
    
    
    list.insertAt(100, 3);
    
    list.displayList();
    cout << endl << "list length: " << list.length() << endl << endl;
    
    
    list.removeAt(3);
    
    list.displayList();
    cout << endl << "list length: " << list.length() << endl << endl;
    
    return 0;
}
