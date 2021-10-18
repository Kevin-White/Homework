#include <iostream>
using namespace std;

void getDimensions(int &, int&);
int getArea(int, int);

int getInt();
void radii(int[], int, int);
void findArea(const int[], double[], int);
void printArrays(const int[], const double[], int);

int main (){
      int num = getInt();
      int size = 10;
      int arr[size];
      double cArea[size];
      radii(arr, size, num);
      cout << arr[0];
      for(int i = 1; i < size; i++){
          cout << ", " << arr[i];
      }
      cout << endl;
      findArea(arr, cArea, size);
      printArrays(arr, cArea, size);
      
      
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

void findArea(const int arr[], double cArea[], int size){
    for(int i = 0; i < size; i++){
        cArea[i] = 3.14 * (arr[i]*arr[i]);
    }
}

void printArrays(const int r[], const double a[], int size){
    for(int i = 0; i < size; i++){
        cout << r[i] << "\t" << a[i] << endl;
    }
}
