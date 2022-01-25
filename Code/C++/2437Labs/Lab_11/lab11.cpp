//2437

#include <iostream>

#include "orderedArrayListType.h"

using namespace std;

void printListInfo(orderedArrayListType<int>& listInfo);

int main()
{
	orderedArrayListType<int> intList;

    //demonstarte the functions: insertOrd, seqOrdSearch & removeOrd
    
    intList.insertOrd(5);
    intList.insertOrd(12);
    intList.insertOrd(35);
    intList.insertOrd(1);
    intList.insertOrd(10);
    intList.insertOrd(55);

    //Question 2
    printListInfo(intList);

    cout<< "\n11 is at index: " << intList.seqOrdSearch(11);
    cout<< "\n35 is at index: " << intList.seqOrdSearch(35) << endl << endl;

    //Question 3
    intList.removeOrd(10);
    cout << "after removing 10:\n";
    printListInfo(intList);

	return 0;
}

void printListInfo(orderedArrayListType<int>& listInfo)
{
	cout << "List: ";
	listInfo.print();

	cout << "List Size: " << listInfo.listSize() << endl;
	cout << "Max List Size: " << listInfo.maxListSize() << endl;

}