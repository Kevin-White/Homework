#include <iostream>
#include "arrayList.h"
using namespace std;
//Kevin White

int main(){
    int length = 10;
    arrayList<int> test(length);

    for(int i = 0; i < length; i++){
        test.insertEnd(i + 1);
    }
    cout << "Current List:\n";
    test.print();
    cout << boolalpha 
    << "Is the array empty: " << test.isEmpty() << endl 
    << "Is the array full: " << test.isFull() << endl;

    test.removeAt(4);
    test.insertAt(4, 500);

    cout << "Current List:\n";
    test.print();
    cout << boolalpha 
    << "Is index 4 = 5: " << test.isItemAtEqual(4, 5) << endl 
    << "Is index 4 = 500: " << test.isItemAtEqual(4, 500) << endl;
    test.clearList();
    cout << "Current List:\n";
    test.print();
    cout << boolalpha 
    << "Is the array empty: " << test.isEmpty() << endl 
    << "Is the array full: " << test.isFull() << endl;

    
    
    test.insertEnd(99);
    test.insertEnd(99);
    test.insertEnd(99);
    test.insertEnd(15);
    test.insertEnd(45);
    test.insertEnd(99);
    test.insertEnd(75);
    test.insertEnd(99);
    test.insertEnd(400);
    cout << "Current List:\n";
    test.print();
    test.removeAll(99);
    cout << "Current List:\n";
    test.print();

}