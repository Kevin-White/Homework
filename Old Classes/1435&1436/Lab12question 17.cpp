#include <iostream>
using namespace std;
void mySwap(int&, int&);
int celsiusDepth(int);
int fahrenheit(int);
int main()
{
   int depth, f, c;
   cout << "Enter depth in kilometers: ";
   cin >> depth;
   c = celsiusDepth(depth);
   f = fahrenheit(c);
   cout << "The temp below the surface of the earth in celsius is: " << c << endl 
   << "in fahrenheit it is: " << f;
 
   
   
}

int celsiusDepth(int d){
 return 10 * d + 20;
 }
 
int fahrenheit(int c){
 return 1.8 * c + 32;
 }