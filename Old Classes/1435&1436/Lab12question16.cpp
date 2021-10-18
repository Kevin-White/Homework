#include <iostream>
using namespace std;
void mySwap(int&, int&);

int main()
{
   int a, b, c;
   cout << "Enter 3 numbers: ";
   cin >> a  >> b >> c;
   mySwap(a,b);
   mySwap(b,c);
   mySwap(a,b);
   cout << a << " " << b << " " << c;
   
   
}

void mySwap(int &x, int &y){
 int temp;
 if(x > y){
     temp = x;
     x = y;
     y = temp;
 }
}