//***************************************************************
// Data Structures 
// Kevin White
// HW 8
// Runner file to test arraylist and linkedQueueType classes
//***************************************************************
#include <iostream>
#include <fstream>
#include "arrayList.h"
#include "clockType.h"
#include "linkedQueueType.h"

using namespace std;

int main()
{
	arrayList<int> intList;
	intList.insert(5);
	intList.insert(8);
	intList.insert(4);
	intList.insert(6);
	intList.insert(7);
	intList.insert(2);
	// add descending sort function and test here
	intList.descendingSelectionSort();
	intList.print();
	// intList.selectionSortDesc();
	// intList.print();
	
	// modify the clockType class and test here
    
    
	arrayList<clockType> myClockList(10);	
	clockType tempClock;
	
	tempClock.setTime(8,16,45);
	myClockList.insert(tempClock);
	tempClock.setTime(6,13,35);
	myClockList.insert(tempClock);	
	tempClock.setTime(6,40,33);
	myClockList.insert(tempClock);	
	tempClock.setTime(7,34,55);
	myClockList.insert(tempClock);	
	tempClock.setTime(7,34,25);
	myClockList.insert(tempClock);

	myClockList.print();
	myClockList.selectionSort();
	myClockList.print();	
	myClockList.descendingSelectionSort();
	myClockList.print();	


	linkedQueueType<int> msTest;

	ifstream infoFile;
    infoFile.open("lab13.dat");
    
    int temp;
    while(infoFile >> temp){
		msTest.addQueue(temp);
    }

	msTest.mergeSort();

	cout << endl;
	msTest.printQueue();

	msTest.printInfo();
	
	return 0;
}
