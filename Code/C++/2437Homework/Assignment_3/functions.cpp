//********************************************************************
//Name: Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 3
//Date:10/04/2021
//Program description: Make Functions for the to minipulate nodes
//*********************************************************************
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T> mergeList(LinkedList<T> & l1, LinkedList<T> & l2);
template <class T>
bool compare(LinkedList<T> & l1, LinkedList<T> & l2);

int main(){
    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> list1Copy;
    

    for(int i = 0; i < 5; i++){
        list1.appendNode(i);
        list2.appendNode(i+5);

        list1Copy.appendNode(i);
    }    

    cout << "List1:" << endl;
    list1.displayList();
    cout << "List2:" << endl;
    list2.displayList();

    LinkedList<int> list3 = mergeList(list1, list2);
    cout << "Merged List:" << endl;
    list3.displayList();
    
    cout << boolalpha << "List 1 and List 2: " << compare(list1, list2) << endl
        << "List 1 and List 1 Copy: " << compare(list1, list1Copy) << endl;
}

template <class T>
LinkedList<T> mergeList(LinkedList<T> & l1, LinkedList<T> & l2){
    LinkedList<int> l3;

    for(int i = 0; i <= l1.getLargestPosition(); i++){
        l3.appendNode(l1.getValueAt(i));
    }
    for(int i = 0; i <= l2.getLargestPosition(); i++){
        l3.appendNode(l2.getValueAt(i));
    }
       return l3;
}

template <class T>
bool compare(LinkedList<T> & l1, LinkedList<T> & l2){
    if(l1.numNodes() == l2.numNodes()){
        for(int i = 0; i < l1.numNodes(); i++){
            if(l1.getValueAt(i) != l2.getValueAt(i)){
                return false;
            }
        }
        return true;
    }
    return false;
}
