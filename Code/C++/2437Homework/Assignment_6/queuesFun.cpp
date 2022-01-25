//********************************************************************
//Name:Kevin White
//Class: COSC 2437 Fall21
//Instructor: Marwa Hassan
//Assignment 6
//Date: 11/5/2021
//Program description: Test new functions for linkedQueue.h
//********************************************************************

#include <iostream>
#include "linkedQueue.h"
using namespace std;

template<class Type>
void print(LinkedQueue<Type> &q);

template<class Type>
Type nElement(LinkedQueue<Type> &q, int n);

template<class Type>
bool isEqualQueues(LinkedQueue<Type> &a, LinkedQueue<Type> &b);

template<class Type>
void divide(LinkedQueue<Type> &q, LinkedQueue<Type> &q1, LinkedQueue<Type>&q2);

template<class Type>
void append(LinkedQueue<Type> &q1, LinkedQueue<Type>&q2);


int main(){

    LinkedQueue<string> brothers;
    brothers.addQueue("Kevin");
    brothers.addQueue("Erik");
    brothers.addQueue("Andrew");
    brothers.addQueue("Ryan");
    LinkedQueue<string> brothersCopy = brothers;

    cout<< "Are Brothers and brothers Copy Equal: "<< boolalpha << isEqualQueues(brothers, brothersCopy) << endl << endl;
    print(brothers); cout << endl;
    cout << "Number of elements in brothers Queue: " << brothers.size() << endl;
    cout << "The 3rd value in the brothers Queue is: " << nElement(brothers, 3) << endl;
    print(brothers); cout << endl << endl;

    brothers.addQueue("Place Holder");
    cout<< "Are Brothers and brothers Copy Equal: "<< boolalpha << isEqualQueues(brothers, brothersCopy) << endl << endl;

    brothers = brothersCopy;
    LinkedQueue<string> older;
    LinkedQueue<string> younger;

    divide(brothers, older, younger);

    cout << "Brothers: "; print(brothers); cout << endl;
    cout << "Older: "; print(older); cout << endl;
    cout << "Younger: "; print(younger); cout << endl;
    append(older,younger);
    cout << "OlderAppendYounger: "; print(older); cout << endl;



}

template<class Type>
void print(LinkedQueue<Type> &q){
    for(int i = 0; i < q.size(); i++){
        cout << q.front() << " ";
        q.addQueue(q.front());
        q.deleteQueue();
    }
}

template<class Type>
Type nElement(LinkedQueue<Type> &q, int n){
    Type ans = {};
    if(n <= q.size()){
        for(int i = 0; i < q.size() + 1; i++){
            if(i == n-1){
                ans = q.front();
                q.deleteQueue();
            }else{
                q.addQueue(q.front());
                q.deleteQueue();
            }
        }
    }
    return ans;
}

template<class Type>
bool isEqualQueues(LinkedQueue<Type> &a, LinkedQueue<Type> &b){
    bool tf = true;
    if(a.size() == b.size()){
        for(int i = 0; i < a.size(); i++){
            if(a.front() != b.front()){
               tf = false; 
            }
            a.addQueue(a.front());
            a.deleteQueue();
            b.addQueue(b.front());
            b.deleteQueue();
        }
    }else{
        tf = false;
    }
    return tf;
}

template<class Type>
void divide(LinkedQueue<Type> &q, LinkedQueue<Type> &q1, LinkedQueue<Type>&q2){
    for(int i = 0; i < q.size(); i++){
        if(i < q.size()/2){
            q1.addQueue(q.front());
            q.addQueue(q.front());
            q.deleteQueue();
        }else{
            q2.addQueue(q.front());
            q.addQueue(q.front());
            q.deleteQueue();
        }
    }
}

template<class Type>
void append(LinkedQueue<Type> &q1, LinkedQueue<Type>&q2){
    if(q2.size() > 0){
        q1.addQueue(q2.front());
        q2.deleteQueue();
        append(q1, q2);
    }
}