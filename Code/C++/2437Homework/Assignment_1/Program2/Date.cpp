#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

void Date::leap(){
    if(year % 4 == 0){
        mDays[1] = 29;
    }else{
        mDays[1] = 28;
    }
}

void Date::clean(){
    while(day > mDays[month-1]){
        day -= mDays[month-1];
        month++;
        if(month > 12){
            month -= 12;
            year++;
            this->leap();
        }
    }
}

Date::Date(){
    month = 1;
    day = 1;
    year = 1899;
}

Date::Date(int m, int d, int y){
    this->setDate(m, d, y);
}

void Date::setDate(int m, int d, int y){
    if(m <= 12){
        month = m;
    }else{
        month = 1;
    }

    year = y;

    this->leap();

    if(d <= mDays[month-1]){
        day = d;
    }else{
        day = 1;
    }
}

void Date::addDays(int d){
    day += d;
    clean();
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

void Date::printDate(){
    cout << month << "/" << day << "/" << year;
}