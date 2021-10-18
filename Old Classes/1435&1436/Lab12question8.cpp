#include <iostream>
using namespace std;
double getLength();
double getWidth();
double getArea(double, double);
void displayData(double, double, double);
int main()
{
   double l, w, a;
   l = getLength();
   w = getWidth();
   a = getArea(l, w);
   displayData(l, w, a);
   
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
double getArea(double length, double width){
    return length * width;
}
void displayData(double length, double width, double area){
 cout << "the length is " << length << " and the width is " << width
 << " the area is " << area;   
}

