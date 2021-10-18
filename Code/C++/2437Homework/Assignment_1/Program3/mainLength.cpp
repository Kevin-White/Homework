#include <iostream>
#include "Length.h"
using namespace std;
//Kevin White
//Worked on with Will Jamison

int main(){
    //Initialize
    Length one(1, 2, 3);
    Length two;
    two.setYard(4);
    two.setFeet(5);
    two.setInch(6);

    //print length;
    cout << "one: " << one << endl;
    cout << "two: " << two << endl << endl;

    if(one == two){
        cout << "one is equal to two ==" << endl;
    } else{
        cout << "one is NOT equal to two ==" << endl;
    }

    if(one < two){
        cout << "two is greater than one <" << endl;
    } else{
        cout << "two is NOT greater than one <" << endl;
    }

    if(one > two){
        cout << "one is greater than two >" << endl;
    } else{
        cout << "one is NOT greater than two >" << endl;
    }

    if(one != two){
        cout << "one is NOT equal to two !=" << endl;
    } else{
        cout << "one is equal to two !=" << endl;
    }

    cout << endl;
    cout << "one plus two is: " << one + two << endl;
    cout << "two minus one is: " << two - one << endl << endl;

    cout << "Change Length of one: " << endl;
    cin >> one;
    
    cout << endl << "New one: " << one << endl;
    cout << "New Two: " << two << endl;

    Length three = one;
    three += two;
    cout << "Three (one + two): " << three << endl;
}