#include <iostream>
using namespace std;

void vfact(int);

int main ()
{
    int fact;
    cout << "Enter factorial Number: ";
    cin >> fact;
    vfact(fact);
    
    
}
void vfact(int x){
    int sum = 1;
    for(int i = x; i > 0; i--){
        sum = sum * i;
    }
    cout << sum;
}
