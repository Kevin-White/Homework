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
    int s1, s2, s3, s4;
    cout << "Enter today's sales for store 1: ";
    cin >> s1;
    cout << "Enter today's sales for store 2: ";
    cin >> s2;
    cout << "Enter today's sales for store 3: ";
    cin >> s3;
    cout << "Enter today's sales for store 4: ";
    cin >> s4;
    cout << "SALES BAR CHART" << endl << "(Each * = $100)" << endl;
    cout << "Store 1: ";
    graph(s1);
    cout << "Store 2: ";
    graph(s2);
    cout << "Store 3: ";
    graph(s3);
    cout << "Store 4: ";
    graph(s4);
}
