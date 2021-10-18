#ifndef Date_H
#define Date_H

#include <string>
#include <iostream>
using namespace std;

class Date;

ostream &operator << (ostream &, const Date &);

class Date{
    private:
        int month;
        int day;
        int year;
        int mDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        void leap();
        void clean();

    public:
        Date();
        Date(int, int, int);
        void setDate(int, int, int);
        void addDays(int);
        int getDay();
        int getMonth();
        int getYear();
        void printDate();

        friend ostream &operator<<(ostream &out, Date &obj){
            out << obj.month << "/" << obj.day << "/" << obj.year;
            return out;
        }
};
#endif