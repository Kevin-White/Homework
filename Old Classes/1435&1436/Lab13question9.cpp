// Kevin White

#include <iostream>
using namespace std;

void graph(int store)
{
    
    for(int i = store/100; i > 0; i--){
        cout << "*";
    }
    cout << endl;
}

int main()
{
    int s[6];
    for(int i = 0; i < 6; i++){
        cout << "Enter today's sales for store " << i + 1 << ": ";
        cin >> s[i];
    }
    cout << "SALES BAR CHART" << endl << "(Each * = $100)" << endl;
    for(int i = 0; i < 6; i++){
        cout << "Store " << i + 1 << ": ";
        graph(s[i]);
    }
}

