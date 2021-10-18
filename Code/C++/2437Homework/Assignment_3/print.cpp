//********************************************************************
//Name: Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 3
//Date:10/04/2021
//Program description: Print one list from the index of another
//*********************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

void listtolistprint(list<int> NumberList, list<int> indexList){
    indexList.sort();
    int iHold = indexList.front();
    int iChange = 0;
    indexList.pop_front();
    list<int>::iterator n = NumberList.begin();
    while(n != NumberList.end()){
        if(iChange == iHold){
            cout << *n << " ";
            iHold = indexList.front();
            indexList.pop_front();
        }
        iChange++;
        n++;
    }
}
    
    
    
 

int main(){
    list<int> first;
    list<int> second;
    
    for(int i = 0; i < 10; i++){
        first.push_back(i*2);
    }
    second.push_back(2);
    second.push_back(3);
    second.push_back(5);
    second.push_back(9);
    listtolistprint(first, second);
}