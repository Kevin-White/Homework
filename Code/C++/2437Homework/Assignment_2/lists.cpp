//********************************************************************
//Name: Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 2
//Date:9/25/2021
//Program description: This Program Shows off the LinkedList class as well as some of the new Functions added
//*********************************************************************
#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

template <class T>
void fillList(LinkedList<T> & list, const string fileName);
template <class T>
void searchList(LinkedList<T> & list, const string fileName);

int main(){
    ifstream inf;
    LinkedList<int> intList;
    LinkedList<string> stringList;

    fillList(intList, "intData.dat");

    fillList(stringList, "strData.dat");

    cout << "Int List:\n"; 
    intList.displayList();
    cout << "String List:\n";
    stringList.displayList();

    cout << "\nInt List Total: " << intList.getTotal() << endl;
    cout << "String List Total: " << stringList.getTotal() << endl << endl;

    cout << "Search Int List:\n";
    searchList(intList, "intSearch.dat");
    cout << "\nSearch String List:\n";
    searchList(stringList, "strSearch.dat");

    cout << endl << endl;
    cout << "Origanal List:\n";
    intList.displayList();
    cout << "\nDeleating The Value: " << intList.deleteLast() << endl;
    cout << "\nNow the list contains:\n";
    intList.displayList();
    cout << "\nDeleating The Value: " << intList.deleteFirst() << endl;
    cout << "\nNow the list contains:\n";
    intList.displayList();
    cout << "\nInserting 99 at the front.\n";
    intList.insertFront(99);
    cout << "Now the list contains:\n";
    intList.displayList();
    cout << "\nInserting 77 at the end.\n";
    intList.insertEnd(77);
    cout << "Now the list contains:\n";
    intList.displayList();

    
}

template <class T>
void fillList(LinkedList<T> & list, const string fileName){
    ifstream inf;
    T hold;
    inf.open(fileName);
    while(inf >> hold){
        list.appendNode(hold);
    }
    inf.close();
}

template <class T>
void searchList(LinkedList<T> & list, const string fileName){
    ifstream inf;
    inf.open(fileName);
    T hold;
    while(inf >> hold){
        if(list.search(hold) == 0){
            cout << hold << " was NOT found in the list" << endl;
        }else{
            cout << hold << " was found in the list" << endl;
        }
    }
    inf.close();
}