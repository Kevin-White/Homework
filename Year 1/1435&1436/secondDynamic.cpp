#include <iostream>
using namespace std;

int getInt();
void rad(int[], int, int);
double *findArea(const int[], int);
void printArrays(const int[], const double*, int);

int main (){
      int num = getInt();
      int size = 10;
      int radii[size];
      
      rad(radii, size, num);
      
      double *cArea = nullptr;
      
      cArea = findArea(radii, size);
      printArrays(radii, cArea, size);
      delete [] cArea;
}

int getInt(){
    int temp;
    cout << "Enter a number: ";
    cin >> temp;
    return temp;
    
}

void rad(int arr[], int size, int user){
    int userOG = user;
    for(int i = 0; i < size; i++){
        arr[i] = user;
        user += userOG;
    }
}

double *findArea(const int arr[], int size){
    double *cArea = new double [size];
    for(int i = 0; i < size; i++){
        cArea[i] = 3.14 * (arr[i]*arr[i]);
    }
    return cArea;
}

void printArrays(const int r[], const double *a, int size){
    for(int i = 0; i < size; i++){
        cout << r[i] << "\t" << a[i] << endl;
    }
}
