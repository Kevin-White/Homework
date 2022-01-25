#include <iostream>
using namespace std;

int largest(int arr[], int size){
    if(size == 1){
        return arr[0];
    }
        int l = largest(arr, size-1);
    if(arr[size-1] > arr[l]){
        return size-1;
    }else{
        return l;
    }
}

int main(){
    const int size = 5;
    int test[size] = {5, 32, 15, 45, 7};

    cout << "The index of the largest value is: " << largest(test, size);
}

