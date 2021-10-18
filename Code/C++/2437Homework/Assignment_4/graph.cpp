#include <iostream>
using namespace std;

void astrisk(int num){
    if(num > 0){
        cout << "*";
        astrisk(num - 1);
    }
}

void chart(int data [] , int size){
    if(size > 0){
        chart(data, size-1);
        cout << data[size-1] << " ";
        astrisk(data[size-1]);
        cout << endl;
    }
}

int main(){
    const int size = 5;
    int data[5]={10,21,16,13,30};

    chart(data, size);
}