#include <iostream>
#include <string>
#include <cctype>


using namespace std;

string cipher(string words, int move);

int main (){
    string words;
    int move;
    cout << "Enter A String: ";
    getline(cin, words);
    cout << "Enter cipher number: ";
    cin >> move;
    words = cipher(words, move);
    cout << words;
    
}

string cipher(string words, int move){
    for(int i = 0; i < words.length(); i++){
        for(int j = 0; j < move; j++){
            if(isalpha(words[i])){
            if(words[i] == 'z'){
                words[i] = 'a';
            }else{
                words[i] = (words[i] + 1);
            }
            }
        }
    } 
    return words;
}
	