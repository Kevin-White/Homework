#include <iostream>
#include<cstring>
#include<string>
#include "linkedQueue.h"
#include "LinkedStack.h"

bool isPalindrome(string word);

int main(){
    string test;
    cout << "Enter a word: ";
    cin >> test;
    cout << boolalpha << "Is \"" << test << "\" a palindrome: " << isPalindrome(test);
}

bool isPalindrome(string word){
    LinkedStack<char> s;
    LinkedQueue<char> q;
    
    for(int i = 0; i < word.length(); i++){
        s.push(tolower(word[i]));
        q.addQueue(tolower(word[i]));
    }

    while(!s.isEmptyStack()){
        if(s.top() != q.front()){
            return false;
        }
        s.pop();
        q.deleteQueue();
    }

    return true;
}