#include <iostream>
using namespace std;

void getDimensions(int &, int&);
int getArea(int, int);

int getInt();
void radii(int[], int, int);

int main (){
      int num = getInt();
      int size = 10;
      int arr[size];
      radii(arr, size, num);
      cout << arr[0];
      for(int i = 1; i < size; i++){
          cout << ", " << arr[i];
      }
      
}

int getInt(){
    int temp;
    cout << "Enter a number: ";
    cin >> temp;
    return temp;
    
}

void radii(int arr[], int size, int user){
    int userOG = user;
    for(int i = 0; i < size; i++){
        arr[i] = user;
        user += userOG;
    }
}
