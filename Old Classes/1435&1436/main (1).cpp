#include <iostream>
using namespace std;
void displayTimes(int, string);
int main()
{
    int times;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "How many times would you like to display the word? ";
    cin >> times;
    displayTimes(times, word);
}

void displayTimes(int times, string w){
    for(int i = 1; i <= times; i++){
        cout << w << endl;
    }
}
