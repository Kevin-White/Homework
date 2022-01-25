#include <iostream>
#include <fstream>
#include "arrayList.h"
#include "linkedQueueType.h"

using namespace std;

int main(){
    arrayList<int> ss(50);
    arrayList<int> qs(50);
    linkedQueueType<int> is;

    ifstream infoFile;
    infoFile.open("lab13.dat");
    
    int temp;
    while(infoFile >> temp){
        ss.insert(temp);
        qs.insert(temp);
        is.addQueue(temp);
    }

    //Part A.1
    cout << "Selection Sort:\n";
    cout << "List Before Sort:\n";
    ss.print();
    cout << endl;

    cout << "List After Sort:\n";
    ss.selectionSort();
    ss.print();

    cout << "Info For Selection Sort:";
    ss.printInfo();

    // Part A.2
    cout << "\n\nQuick Sort:\n";
    cout << "List Before Sort:\n";
    qs.print();
    cout << endl;

    cout << "List After Sort:\n";
    qs.quickSort();
    qs.print();

    cout << "Info For Quick Sort:";
    qs.printInfo();

    //Part B
    cout << "\n\nInsertion  Sort:\n";
    cout << "List Before Sort:\n";
    is.printQueue();
    cout << endl;

    cout << "List After Sort:\n";
    is.linkedInsertionSort();
    is.printQueue();

    cout << "\nInfo For Insertion Sort:";
    is.printInfo();
    
}