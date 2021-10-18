#include <string>
#include <iostream>
#include "myStack.h"
using namespace std;

template <class T>
void displayStack(stackType<T> st);

template <class T>
void swapTwo(stackType<T> &st);

template <class Type>
void appendStack(stackType<Type> &a, stackType<Type> &b);

int main(){
    stackType<string> brothers = 8;
    brothers.push("Kevin");
    brothers.push("Erik");
    brothers.push("Andrew");
    brothers.push("Ryan");

    cout << "Question 2\n";
    displayStack(brothers);
    cout << "\nQuestion 3\n";
    swapTwo(brothers);
    displayStack(brothers);

    cout << "\nQuestion 4\n";
    stackType<string> friends = 8;
    friends.push("Will");
    friends.push("Amado");
    displayStack(friends);
    displayStack(brothers);
    appendStack(friends, brothers);
    displayStack(friends);

    stackType<int> stack1 = 8;
    stackType<int> stack2 = 8;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack2.push(5);
    stack2.push(6);
    stack2.push(7);
    stack2.push(8);

    displayStack(stack1);
    displayStack(stack2);
    appendStack(stack1, stack2);
    displayStack(stack1);

}


template <class T>
void displayStack(stackType<T> st){
    if(!st.isEmptyStack()){
        cout << st.top() << " ";
        st.pop();
        displayStack(st);
    }else{
        cout << endl;
    }
}

template <class T>
void swapTwo(stackType<T> &st){
    T hold1 = st.top();
    st.pop();
    T hold2 = st.top();
    st.pop();
    st.push(hold1);
    st.push(hold2);
}

template <class T>
void appendStack(stackType<T> &a, stackType<T> &b){
    if(!a.isFullStack() && !b.isEmptyStack()){
        T hold = b.top();
        b.pop();
        appendStack(a, b);
        a.push(hold);
    }
}