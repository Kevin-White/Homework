// Kevin White
#include <iostream>
using namespace std;

int sequentialSearch(const int [], int, int);

int main(){
 int size = 10;
 int arr[size] = {123, 267, 297, 335, 555, 624, 777, 794, 856, 931};
 int target;
 cout << "Enter a target number: ";
 cin >> target;
 int found = sequentialSearch(arr, size, target);
 if(found != -1){
     cout << "Found the target at index: " << found;
 } else {
     cout << "target not found";
 }
 
}

int sequentialSearch(const int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

