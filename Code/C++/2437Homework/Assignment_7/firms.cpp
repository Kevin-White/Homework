//********************************************************************
//Name: Kevin White
//Class: COSC 2437 F21
//Instructor: Marwa Hassan
//Assignment 7
//Date: 11/16/2021
//Program description: Tests out both the hashT and FirmData Functions
//*********************************************************************
#include <iostream>
#include "hashT.h"
#include "FirmData.h"
#include <fstream>
using namespace std;

int hashFunc(string name)
{
int i = 0, sum = 0;
int len = name.length();
for (int k = 0; k < 25-len; k++)
 name = name + ' '; //increase the length of name to 25 characters
for (int k = 0; k < 5; k++)
{
 sum = sum + static_cast<int>(name[i]) * 128 * 128
 + static_cast<int>(name[i + 1]) * 128
 + static_cast<int>(name[i + 2]);
 i = i + 3;
}
return sum % 101;
}

int main(){
    hashT<FirmData> firms(101);
    FirmData hold;
    ifstream firmFile;
    firmFile.open("firm.dat");

    string throwAway;

    while(firmFile >> hold){
        firms.insert(hashFunc(hold.getName()), hold);
    }

    firms.print();
    
    string firm1 = "Whole Foods Market";

    bool found = false;
    int nameVal = hashFunc(firm1);
    hold.setName(firm1);
    firms.search(nameVal, hold, found);
    cout<< "Is \'" << firm1 << "\' in the table: " << boolalpha << found << endl << endl;

    string firm2 = "Pizza Hut";

    found = false;
    nameVal = hashFunc(firm2);
    hold.setName(firm2);
    firms.search(nameVal, hold, found);
    cout<< "Is \'" << firm2 << "\' in the table: " << boolalpha << found << endl;
    firms.remove(nameVal, hold);
    cout << "Remove \'" << firm2 << "\' from hash table" << endl;
    firms.search(nameVal, hold, found);
    cout<< "Is \'" << firm2 << "\' in the table: " << boolalpha << found << endl << endl;

    string firm3 = "Real Name Of Real Thing";

    found = false;
    nameVal = hashFunc(firm3);
    hold.setName(firm3);
    firms.search(nameVal, hold, found);
    cout<< "Is \'" << firm3 << "\' in the table: " << boolalpha << found << endl << endl;




}