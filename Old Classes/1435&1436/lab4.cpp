#include <iostream>
using namespace std;
int getAverage(const int *arr, int size);
int getLargest(const int *arr, int size);
int getSecondLargest(const int *arr, int size);

main(){
    int num;
    int *arr;
    cout << "How many values would you like to process: ";
    cin >> num;
    while(num <= 0){
        cout << "Enter a positive number: " << endl;
        cin >> num;
    }
    arr = new int [num];
    for(int i = 0; i < num; i++){
        cout << "Enter a number for value " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "The average of the values are: " << getAverage(arr, num) << endl;
    cout << "The largest value is: " << getLargest(arr, num) << endl;
    cout << "The second largest value is: " << getSecondLargest(arr, num) << endl;
    delete [] arr;
}

int getAverage(const int *arr, int size){
    int ave = 0;
    for(int i = 0; i < size; i++){
        ave += arr[i];
    }
    return ave/size;
}

int getLargest(const int *arr, int size){
    int largest = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i]> largest){
            largest = arr[i];
        }
    }
    return largest;    
}

int getSecondLargest(const int *arr, int size){
    int largest = arr[0];
    int second = arr[1];
    for(int i = 1; i < size; i++){
        if(arr[i]> largest){
            second = largest;
            largest = arr[i];
        }else if(arr[i] > second){
            second = arr[i];
        }
    }
    return second;    
}
