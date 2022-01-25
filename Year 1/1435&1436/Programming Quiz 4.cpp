#include <iostream>
using namespace std;

int * dSquare(int first, int last); 
main (){
    int first;
    int last;
    int * arr = nullptr;
    
    cout << "Enter A number: ";
    cin >> first;
    cout << "Enter Another Number: ";
    cin >> last;
    while(first == last){
        cout << "The numbers must be different, Try again: ";
        cout << "Enter A number: ";
        cin >> first;
        cout << "Enter Another Number: ";
        cin >> last;
    }
    if(first > last){
        int hold = first;
        first = last;
        last = hold;
    }
    
    arr = dSquare(first, last);
    
    cout << "All of  the squares between " << first << " & " << last << endl;
    for(int i = 0; i < (last-first) + 1; i++){
        cout << arr[i] << " ";
    }
}


int * dSquare(int first, int last){
    int size = (last - first) + 1;
    int * arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = (first + i) * (first + i);
    }
    return arr;
}