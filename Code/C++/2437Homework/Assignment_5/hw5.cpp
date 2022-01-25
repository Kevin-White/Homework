//*******************************************************************
//Name: Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 5
//Date: 10/21/2021
//Program description: Uses the Stacks in order to test what we know
//*******************************************************************
#include <iostream>
#include "LinkedStack.h"
using namespace std;

template <class Type>
LinkedStack<Type> evenNubmers(LinkedStack<Type> full);

void toBinary(int num);

int main(){
    LinkedStack<int> stackALL;
    LinkedStack<int> stackEVEN;

    stackALL.push(4);
    stackALL.push(5);
    stackALL.push(3);
    stackALL.push(2);
    stackALL.push(6);
    stackALL.push(9);
    stackALL.push(2);

    stackEVEN = evenNubmers(stackALL);


    cout << "Question 1:\n";
    cout << "Full Stack\tEven Stack\n";
    while(!stackALL.isEmptyStack()){
        cout << stackALL.top() << "\t\t";
        stackALL.pop();

        if(!stackEVEN.isEmptyStack()){
            cout << stackEVEN.top();
            stackEVEN.pop();
        }
        cout << endl;
    }

    cout << "\n\nQuestion 2:\n";
    cout << "7 in binary: ";
    toBinary(7);
    cout << "10 in binary: ";
    toBinary(10);
}


template <class Type>
LinkedStack<Type> evenNubmers(LinkedStack<Type> full){
    LinkedStack<Type> even;
    LinkedStack<Type> hold = full;
        while(!full.isEmptyStack()){
            if((full.top() % 2 )== 0){
                even.push(full.top());
            }
            full.pop();
        }
    full = hold;

    LinkedStack<Type> evenFliped;
    while(!even.isEmptyStack()){
        evenFliped.push(even.top());
        even.pop();
    }

    return evenFliped;
}

void toBinary(int num){
    LinkedStack<int> binary;
    
    while(num > 0){
        binary.push(num % 2);
        num = num/2;
    }

    while(!binary.isEmptyStack()){
        cout << binary.top();
        binary.pop();
    }
    cout << endl;

}

