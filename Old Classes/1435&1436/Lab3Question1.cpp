#include <iostream>

using namespace std;

int main()
{
    int size = 7;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7};
    
    cout << "the array looks like this: \n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";    
    }
    
    int hold = arr[size-1];
    for(int i = size -2; i >= 0; i--){
        arr[i+1]=arr[i]; 
    }
    arr[0] = hold;
    
    cout << "\nthe array looks like this: \n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";    
    }
}
