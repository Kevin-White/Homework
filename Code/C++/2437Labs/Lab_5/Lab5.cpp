#include <iostream>
#include "LinkedList.h"
using namespace std;
//Kevin White

int main(){
    LinkedList<int> test;
    test.appendNode(10);
    test.appendNode(50);
    test.appendNode(40);

    cout << "Total : " << test.getTotal() << endl;
    cout << "Number Of Nodes: " << test.numNodes() << endl;

    cout << "Return index 1: " << test.getValueAt(1) << endl;
    
    cout << "Return Average: " << test.getAverage() << endl;

    cout << "Return Largest: " << test.getLargest() << endl;

    cout << "Return Largest Possition: " << test.getLargestPosition() << endl;

    cout << "Return Smallest: " << test.getSmallest() << endl;

    cout << "Return Smallest Possition: " << test.getSmallestPosition() << endl;


}