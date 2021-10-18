//Kevin White
#include <iostream>
using namespace std;


struct Distance{
  int feet;
  float inch;
};

Distance getSum(Distance d1, Distance d2);
void fixSum(Distance & sum);

int main (){
  Distance d1, d2, sum;
  cout << "Enter 1st distance," << endl;
  cout << "Enter feet: ";
  cin >> d1.feet;
  cout << "Enter inch: ";
  cin >> d1.inch;
  cout << "Enter 2nd distance" << endl;
  cout << "Enter feet: ";
  cin >> d2.feet;
  cout << "Enter inch: ";
  cin >> d2.inch;
  
  sum = getSum(d1, d2);
  fixSum(sum);
  
  cout << "The sum of the 2 distances is: " << endl
  << sum.feet << " Feet & " << sum.inch << " Inches";
}
  
Distance getSum(Distance d1, Distance d2){
    Distance sum;
    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;
    return sum;
}

void fixSum(Distance & sum){
    while(sum.inch >= 12){
        sum.feet++;
        sum.inch -= 12;
    }
}

