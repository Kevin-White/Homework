//********************************************************************
//Name:Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 4 Problem 1
//Date: 3/12/2021
//Program description: This program takes a user made array and edits and manipulates he array to make new ones and finds the mode
//*********************************************************************


#include <iostream>
using namespace std;

int *reverse(const int arr[], int size);
int *combine(const int arr[], const int rev[], int size);
void rotate(int arr[], int size);
int mode(const int arr[], int size);

int main()
{
    int * arr = nullptr;
    int size;
    int * rev = nullptr;
    int * com = nullptr;
    int * rot = nullptr;
    bool check;
    
    //Make Array Size While > 0
    cout << "Enter the size of the array: ";
    cin >> size;
    while(size <= 0){
        cout << "Enter a size >0: ";
        cin >> size;
    }
    arr = new int[size];
    
    //Fills In Values For Array While > 0
    cout << "Enter array values: ";
    do{
        check = true;
    for(int i = 0; i < size; i++){
    cin >> arr[i];
    if(arr[i] <= 0){
        check = false;
    }
    }
    if(!check){
        cout << "Values must be >0: ";
    }
    }while(!check);
    cout << endl;
    
    //Displays Information
    rev = reverse(arr, size);
    cout << "Values in reverse order:" << endl;
    for(int i = 0; i < size; i++){
        cout << rev[i] << " ";
    }
    cout << endl << "--------------------" << endl;
    
    com = combine(arr, rev, size);
    cout << "Values in combined array: " << endl;
    for(int i = 0; i < size*2; i++){
        cout << com[i] << " ";
    }
    cout << endl <<"--------------------" << endl;
    
     rotate(rev, size);
    cout << "Values rotated to the right two places:" << endl;
    for(int i = 0; i < size; i++){
        cout << rev[i] << " ";
    }
    cout << endl << "--------------------" << endl;
    
    cout << "The mode is: " << mode(arr, size);
    
}


//*************************************************
// reverse function
// This function takes a list and returns the poiner of a new one in reverse order
// 
// Return Value
// ------------
// pointer of a dynamic arr that is reversed
//
// Parameters
// ------------
// const int arr[]: Array made by the user
// int size: The size of the array
//*************************************************
int *reverse(const int arr[], int size){
    int * rev = new int [size];
    for(int i = 0; i < size; i++){
        rev[i] = arr[(size - 1) - i];
    }
    return rev;
}


//*************************************************
// combine function
// This function takes 2 arrays and combines them into 1 new array
// 
// Return Value
// ------------
// pointer of a dynamic arr that is the combinaion of 2 arrays
//
// Parameters
// ------------
// const int arr[]: Array made by the user
// int size: The size both arrays
// const int rev[]: The reverse of arr
//*************************************************
int *combine(const int arr[], const int rev[], int size){
    int * com = new int [size*2];
    for(int i = 0; i < size; i++){
       com[i] = arr[i]; 
    }
    for(int i = size; i < size*2; i++){
       com[i] = rev[i-size]; 
    }
    return com;
}

//*************************************************
// rotate function
// This function takes a list and rotates it 2 to the right
// 
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// int arr[]: Array made by the user that will be rotated 2 to the right inside of he function
// int size: The size of the array
//*************************************************
void rotate(int arr[], int size){
    for(int j = 0; j < 2; j++){
    int hold = arr[size -  1];
    for(int i = size - 2; i > -1; i--){
        arr[i + 1] = arr[i];
    }
    arr[0] = hold;
    }
}


//*************************************************
// mode function
// This function finds the mode of the user made array or returns -1 if noting is found
// 
// Return Value
// ------------
// the mode of the array or -1
//
// Parameters
// ------------
// const int arr[]: Array made by the user
// int size: The size of the array
//*************************************************
int mode(const int arr[], int size){
    int mode = -1;
    int count = -1;
    int count2 = -1;
    for(int i = 0; i< size; i++){
        int hold = 0;
        while(arr[i] == mode){
         i++;
         if(i >= size && count > count2){
             return mode;
         }else{
             return -1;
         }
        }
        for(int j = 0; j < size; j++){
            if(arr[j] == arr[i]){
                hold++;
            }
        }
        if(hold > count){
            count2 = count;
            count = hold;
            mode = arr[i];
        }
        
    }
    if(count > count2){
        return mode;
    }else{
        return -1;
    }
    
}




