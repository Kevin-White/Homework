// Kevin White
#include <iostream>
using namespace std;

int oddVals(const int [], int);

int main(){
    int size = 11;
    int arr[11];
    int sum = 0;
    for(int i = 0; i < size-1; i++){
        cout << "Enter in the number for spot " << i+1 << " of 10: ";
        cin >> arr[i];
        sum += arr[i];
    }
    arr[10] = sum / 10;
    cout << "\rYour array is: " << endl;
    for(int val : arr){
        cout << val << " ";
    }
    cout << "\rThe number of odd numbers in your list is: " << oddVals(arr, size);
}

int oddVals(const int arr[], int size){
    int numOdd = 0;
    for(int i = 0; i < size; i++){
     if(arr[i] % 2){
         numOdd++;
     }   
    }
    return numOdd;
    
}
