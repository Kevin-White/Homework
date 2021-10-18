#include <iostream>
using namespace std;

int main()
{
    int size = 4;
    int oneD[size];
    int twoD[size][size];
    cout<<"Values in the 2D array" << endl;
    for(int i = 0; i < size; i++){
       for(int j = 0; j < size; j++){
           twoD[j][i] = i+j+2;
           cout << twoD[j][i] << " ";
           if(i == j){
               oneD[i] = twoD[j][i];
           }
       } 
       cout << endl;
    }
    cout<<"Values in the 1D array" << endl;
    for(int i = 0; i < size; i++){
        cout << oneD[i] << " ";
    }
    
}
