#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string toggle(string words, int num);
string insertRandomNumber(string words, int num);
string capitalize(string words);

main (){
    
    string words;
    int index;
    
    //Lab6 Question 1
    cout << "Enter a string: ";
    getline(cin, words);
    cout << "Enter a character position to toggle: ";  
    cin >> index;
    words = toggle(words, index);
    cout << words << endl;
    
    //Lab6 Question 2
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, words);
    cout << "Enter a character position to add a number: "; 
    cin >> index;
    words = insertRandomNumber(words, index);
    cout << words << endl;
    
    //Lab6 Question 3
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, words);
    words = capitalize(words);
    cout << words << endl;

    
  
}

string toggle(string words, int num){
    if(isalpha(words[num])){
        if(isupper(words[num])){
            words[num] = tolower(words[num]);
        }else{
            words[num] = toupper(words[num]);
        }
    }
    return words;
}

string insertRandomNumber(string words, int num){
    if(num < words.length()){
        unsigned seed = time(0);
        srand(seed);
        int rnum = rand() % 10;
        words.insert(num, to_string(rnum));
    }
    
    return words;
}

string capitalize(string words){
    if(words.length() >= 3){
        words[1] = toupper(words[1]);
        words[2] = toupper(words[2]);
    }
    return words;
}
