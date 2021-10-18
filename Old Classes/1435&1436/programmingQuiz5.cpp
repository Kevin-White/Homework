//Kevin White
#include <iostream>
using namespace std;

int countT(string input);

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    cout << "The letter 't' is in the string: '" << input << "' " << countT(input) << " times.";
}

int countT(string input){
    int count = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == 't' || input[i] == 'T'){
            count++;
        }
    }
    return count;
}