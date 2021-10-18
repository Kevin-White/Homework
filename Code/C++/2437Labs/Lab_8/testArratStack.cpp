#include <string>
#include <iostream>
#include "myStack.h"
using namespace std;

int main(){
    stackType<string> brothers = 4;

    cout << boolalpha << "Is the stack empty: " << brothers.isEmptyStack() << endl;

    brothers.push("Kevin");
    brothers.push("Erik");
    brothers.push("Andrew");
    brothers.push("Ryan");

    cout << boolalpha << "Is the stack empty: " << brothers.isEmptyStack() << endl;
    cout << boolalpha << "Is the stack full: " << brothers.isFullStack() << endl;

    cout << "Brothers List: " << endl;
    for(int i = 0; i < 4; i++){
        cout << brothers.top() << endl;
        brothers.pop();
    }
}