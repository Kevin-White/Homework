#include <iostream>
using namespace std;

int main ()
{
    int fact;
    int sum = 1;
    cout << "Enter factorial Number: ";
    cin >> fact;
    for(int i = fact; i > 0; i--){
        sum = sum * i;
    }
    cout << sum;
}