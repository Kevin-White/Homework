//Write your name here

#include <iostream>

using namespace std;

 

//function prototype
double adjustGrades(int [], int);

int main(){
    int numbers[100];
    int count = 0;
    int hold;
    cout << "Enter a number and 0 when you're done: ";
    cin >> hold;
    while(count < 100 && hold != 0){
        numbers[count] = hold;
        count++;
        cout << "Enter a number and 0 when you're done: ";
    cin >> hold;
    }
    cout << "You entered these numbers in reverce order:" << endl;
    for(int i = count-1; i >= 0; i--){
        cout << numbers[i] << endl;
    }

}

 

