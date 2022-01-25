#include <iostream>
using namespace std;
void printArray(int arr[], int size);
int main()
{
    //Init Vars
    int size = 7;
    int arr[size] = {7, 9, 2, 5, 6, 8, 10};
    
    //Prints array
    printArray(arr, size);
    
    //moves array to the left
    int hold = arr[0];
    for(int i = 1; i < size; i++){
        arr[i - 1] = arr[i];
    }
    arr[size - 1] = hold;
    
    //Pritns Array
    printArray(arr, size);

}
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}