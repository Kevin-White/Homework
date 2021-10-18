#ifndef Length_H
#define Length_H

#include <string>
#include <iostream>
using namespace std;
//Kevin White
//Worked on with Will Jamison

class Length;

ostream &operator << (ostream &, const Length &);
istream &operator >> (istream &, Length &);

class Length
{
    private:
        int yards;
        int feet;
        int inches;

        void Clean();
    
    public:
        Length();
        Length(int, int, int);
        void setYard(int);
        int getYard();
        void setFeet(int);
        int getFeet();
        void setInch(int);
        int getInch();

        Length operator+(const Length &);
        Length operator+(const int);
        Length operator-(const Length &);

        void operator=(const Length &);

        bool operator==(const Length &);
        bool operator<(const Length &);
        bool operator>(const Length &);
        bool operator!=(const Length &);

        void operator+=(const Length &);
        void operator+=(const int);

        friend ostream &operator<<(ostream &, const Length &);
        friend istream &operator>>(istream &, const Length &);


        friend ostream &operator<<(ostream &strm, const Length &obj){
            strm << obj.yards << " Yards, " << obj.feet << " feet, and " << obj.inches << " inches.";
            return strm;
        }

        friend istream &operator>>(istream &strm,  Length &obj){
            cout << "Enter Yards: ";
            strm >> obj.yards;
            cout << "Enter Feet: ";
            strm >> obj.feet;
            cout << "Enter Inches: ";
            strm >> obj.inches;
            return strm;
        }
};
#endif