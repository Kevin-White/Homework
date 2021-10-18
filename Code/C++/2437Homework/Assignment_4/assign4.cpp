#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList<int> test;

    for(int i = 0; i < 10; i++){
        test.appendNode(i);
    }
    test.printList();
    test.printListReverse();
    test.printListSkip();
    cout << "There are " << test.recursiveNumNode() << " nodes in this list";
    cout << boolalpha << "\nIs 5 in the list: " << test.sequentialSearch(5);
    cout << boolalpha << "\nIs 15 in the list: " << test.sequentialSearch(15);
}
