//********************************************************************
//Name:Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 3 Problem 2
//Date:2/17/2021
//Program description: Gets data from data.dat and orgonizes it the searches for a user input in the array
//*********************************************************************
#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
void insertionSort(int [], int);
int median(const int [], int);
void showArray(const int [], int);
int binarySearch(const int arr[], int, int);


int main()
{
    ifstream inFile;
    string fileName;
    int size = 40;
    int data [size];
    int hold;
    int count = 0;
    int num;
    int found;
    
    cout << "What file would you like to open: ";
    cin >>fileName;
    inFile.open(fileName);
    while(!inFile){
        inFile.close();
        cout << "This file does not exist!\n Try again or q to quit: ";
        cin >> fileName;
        if(fileName == "q"){
            return 0;
        }
        inFile.open(fileName);
    }
    
    cout << "Enter an int: ";
    cin >> num;
    
    while(inFile >> hold && count < size){
        data[count] = hold;
        count++;
        }
        inFile.close();
    showArray(data, size);
    insertionSort(data, size);
    showArray(data, size);
    cout << "\nThe median of the data is: " << median(data, size) << endl;
    found = binarySearch(data, size, num);
    if(found == -1){
        cout << "Your number was not inside of the array";
    }else{
        cout << num << " Was found at index " << found;
    }
    
}

//*************************************************
// insertionSort function
// Sorts an array through inssertion sort
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// int list[] A list of all the numbers
// int size   The size of the list
//*************************************************
void insertionSort(int list[], const int size){
    int pivot = 0;
    while(pivot <size){
        int temp = list[pivot];
        int i = pivot -1;
        while(i>= 0 && list[i] > temp){
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = temp;
        pivot++;
    }
}

//*************************************************
// median function
// Finds the median
// 
// Return Value
// ------------
// int the median
//
// Parameters
// ------------
// int data[] a list of numbers
// int size   the size of the list
//*************************************************
int median(const int data[], const int size){
    return data[size/2];
}
//*************************************************
// showArray function
// Shows the array to the user
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// int list[]   A list of numbers
// int size     The size of the list
//*************************************************
void showArray(const int list[], const int size){
    cout << "\nValues in the array:\n| ";
    for(int i = 0; i < size; i++){
        cout << list[i] << " | ";
        if(((i + 1) % 10) == 0 && i != 39){
            cout << endl << "| ";
        }
    }
}
//*************************************************
// binarySearch function
// Searches for a number in a list
// 
// Return Value
// ------------
// int the index if found or -1
//
// Parameters
// ------------
// int arr  a list full of numbers
// int size the size of the list
// int target the value that the function is looking for in the list
//*************************************************
int binarySearch(const int arr[], int size, int target){
    int first = 0;
    int last = size -1;
    while(last >= first){
        int mid = (first + last)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            last = mid -1;
        }else if(arr[mid] < target){
            first = mid + 1;
        }
    }
    return -1;
}
