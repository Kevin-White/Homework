//********************************************************************
//Name:Kevin White          
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 2 Problem 1
//Date:2/8/2021
//Program description: Looks through 1 array 2 different ways to search for a number and outputs the number of comparisons it took.
//*********************************************************************

#include <iostream>
#include<math.h>
#include<ctime>
using namespace std;

int seqSearch(const int [], int , int);
int biSearch(const int [], int , int);

int main()
{
    int size = 50;
    int arr[size];
    int target;
    int seq;
    int bi;
    for(int i = 0; i < 250; i += 5){
        arr[i/5] = i;
    }
    cout << "What is you'r target number: ";
    cin >> target;
    seq = seqSearch(arr, size, target);
    if(seq == -1){
        cout << "not found" << endl;
    }else{
        cout << "found in " << seq << " comparisons in seqSearch" << endl;
    }
    bi = biSearch(arr, size, target);
    if(bi == -1){
        cout << "not found" << endl;
    }else{
        cout << "found in " << bi << " comparisons in biSearch" << endl;
    }
}

// seqSearch function
// This function looks for a target inside of an array using sequential search
//
// Return Value
// ------------
// int  returns the number of comparisons it took or -1 if not found
//
// Parameters
// ------------
// const int array[]      the array to look through
// int size               the size of the array to help the algoritum
// int target             the target the function is looking for in the array
//*************************************************
int seqSearch(const int arr[], int size, int target){
    int comparisons = 0;
    for(int i = 0; i < size; i++){
        comparisons++;
        if(arr[i] == target){
            return comparisons;
        }
    }
    return -1;
}
// biSearch function
// This function looks for a target inside of an array using binary search
//
// Return Value
// ------------
// int returns the number of comparisons it took or -1 if not found
//
// Parameters
// ------------
// const int array[]      the array to look through
// int size               the size of the array to help the algoritum
// int target             the target the function is looking for in the array
//*************************************************
int biSearch(const int arr[], int size, int target){
    int left = 0;
    int right = size -1;
    int comparisons = 0;
    while(right >= left){
        int mid = (left + right)/2;
        comparisons++;
        if(arr[mid] == target){
            return comparisons;
        }else if(arr[mid] > target){
            right = mid -1;
        }else if(arr[mid] < target){
            left = mid + 1;
        }
    }
    return -1;
}


