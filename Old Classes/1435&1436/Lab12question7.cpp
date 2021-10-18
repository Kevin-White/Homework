#include <iostream>
using namespace std;
double getLength();
double getWidth();
int main()
{
   double l, w;
   l = getLength();
   w = getWidth();
   cout << "the length is " << l << " and the width is " << w;
   
}

double getLength(){
    double length;
    cout << "Enter the length for a rectangle: ";
    cin >> length;
    return length;
}
double getWidth(){
    double width;
    cout << "Enter the width for a rectangle: ";
    cin >> width;
    return width;
}