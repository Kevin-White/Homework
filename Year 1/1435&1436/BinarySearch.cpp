// Kevin White
#include <iostream>
using namespace std;

int binarySearch(const int [], int, int);

int main(){
 int size = 10;
 int arr[size] = {123, 267, 297, 335, 555, 624, 777, 794, 856, 931};
 int target;
 cout << "Enter a target number: ";
 cin >> target;
 int found = binarySearch(arr, size, target);
 if(found != -1){
     cout << "Found the target at index: " << found;
 } else {
     cout << "target not found";
 }
 
}

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

