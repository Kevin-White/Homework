#include <iostream>
#include <fstream>
using namespace std;
void display(string [], int);
void insertionSort(string [], int);

int main()
{
    int size = 20;
    string names[size];
    fstream inFile;
    inFile.open("names.dat");
    
    for(int i = 0; i < size; i++){
        getline(inFile, names[i]);
    }
    
    display(names, size);
    insertionSort(names,size);
    display(names, size);
    
}

void display(string arr[], int size){
    cout << "\n\nThe array: \n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

void insertionSort(string arr[], int size){
    int pivot = 1;
    while(pivot < size){
        string temp = arr[pivot];
        int i = pivot -1;
        while(i >= 0 && arr[i] > temp){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = temp;
        pivot = pivot + 1;
    }
}
