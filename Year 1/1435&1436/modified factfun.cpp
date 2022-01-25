#include <iostream>
using namespace std;

int vfact(int);

int main ()
{
    int fact;
    cout << "Enter factorial Number: ";
    cin >> fact;
    fact = vfact(fact);
    cout << fact;
    
    
}
int vfact(int x){
    int sum = 1;
    for(int i = x; i > 0; i--){
        sum = sum * i;
    }
    return sum;
}
