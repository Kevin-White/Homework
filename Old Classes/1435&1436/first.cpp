#include <iostream>
using namespace std;

void getDimensions(int &, int&);
int getArea(int, int);



int main (){
int radius;
int length;
int width;
cout << "Enter in the radius: ";
cin >> radius;
getDimensions(length, width);
cout << "The area of the rectangle is: " << getArea(length, width);
}

void getDimensions(int &l, int &w){
    cout << "Enter in the length: ";
    cin >> l;
    cout << "Enter in the width: ";
    cin >> w;
}

int getArea(int l, int w){
    return l * w;
}



