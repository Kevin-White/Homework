#include <iostream>

using namespace std;
void swapArr(int [], int [], int);
int main()
{
    int size = 10;
    int arrPositive[size] = {1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};
    int arrNegitive[size] = {-1, -2, -3 ,-4 ,-5 ,-6 ,-7 ,-8 ,-9 ,-10};
    cout<<  "Things in the arrNegitive are: " << endl;   
    for(int i = 0; i < size; i++){
        cout << arrNegitive[i] << endl;
    }
    cout<<  "\nThings in the arrPositive are: " << endl;   
    for(int i = 0; i < size; i++){
        cout << arrPositive[i] << endl;
    }
    swapArr(arrPositive, arrNegitive, size);
    cout<<  "Things in the arrNegitive are: " << endl;   
    for(int i = 0; i < size; i++){
        cout << arrNegitive[i] << endl;
    }
    cout<<  "\nThings in the arrPositive are: " << endl;   
    for(int i = 0; i < size; i++){
        cout << arrPositive[i] << endl;
    }
}


void swapArr(int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
        int hold = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = hold;
    }
}