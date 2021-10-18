#include <iostream>
#include "Date.h"
using namespace std;


int main(){
    Date test(9, 6, 2021);
    test.printDate(); cout << endl;

    //adds days to christmas
    test.addDays(110);
    test.printDate(); cout << endl;

    //adds days to last day of febuary 2022
    test.addDays(65);
    test.printDate(); cout << endl;

    //adds 1 day on NON leap year;
    test.addDays(1);
    test.printDate(); cout << endl;

    //set date to day before extra day in a leep year
    test.setDate(2, 28, 2024);
    test.printDate(); cout << endl;

    //adds 1 day on leap year;
    test.addDays(1);
    test.printDate(); cout << endl;

    cout << endl;

    Date birthday;
    birthday.printDate(); cout << endl;
    birthday.setDate(10, 27, 2001);

    cout << "I was born in the year: " << birthday.getYear() << endl
    << "I was born in the month: " << birthday.getMonth() << endl
    << "I was born on the day: " << birthday.getDay() << endl;

    cout << "my birthday is: " << birthday;


}