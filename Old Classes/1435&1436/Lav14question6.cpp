//Write your name here

#include <iostream>
#include<iomanip>

using namespace std;

 

//function prototyp
void display(int [], int, int);

int main(){
    int size = 10;
    int numbers[size] = {22, 123, 42, 9, 643, 684, 53, 12, 517, 65};
    int n;
    cout << "Enter a number: ";
    cin >> n;
    display(numbers, size, n);
    
    
}
 

void display(int numbers[], int size, int n){
    cout << "All numbers biger than entered number in array:" << endl;
    for(int i = 0; i < size; i++){
        if(numbers[i] > n){
            cout << numbers[i] << " at index " << i << endl;
        }
    }
}