#include <iostream>
#include <fstream>
#include "LinkedStack.h"
using namespace std;

bool balance(string file);

int main(){
    ifstream infile;
    infile.open("test.txt");
    string words;
    infile >> words;
    cout << words << endl;
    cout << boolalpha << "Is balanced: " << balance("test.txt") << endl << endl;

    infile.close();
    infile.open("test2.txt");
    infile >> words;
    cout << words << endl;
    cout << boolalpha << "Is balanced: " << balance("test2.txt") << endl << endl;
}

bool balance(string file){
    ifstream infile;
    infile.open(file);
    char hold;
    char poped;
    LinkedStack<char> stack;
    while(infile >> hold){
        if(hold == '(' || hold == '{' || hold == '['){
            stack.push(hold);
        }
        else if(hold == ')' || hold == '}' || hold == ']'){
            if(stack.isEmptyStack()){
                return false;
            }else{
                poped = stack.top();
                stack.pop();
                if(!((poped == '(' && hold == ')') || (poped == '{' && hold == '}') || (poped == '[' && hold == ']'))){
                    return false;
                }
            }
        }
    }
    if(!stack.isEmptyStack()){
        return false;
    }
    return true;
}


