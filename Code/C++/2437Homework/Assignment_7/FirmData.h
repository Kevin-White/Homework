//********************************************************************
//Name: Kevin White
//Class: COSC 2437 F21
//Instructor: Marwa Hassan
//Assignment 7
//Date: 11/16/2021
//Program description: Holds information about firms from firm.dat
//*********************************************************************
#ifndef FirmData_H
#define FirmData_H

#include <string>
#include <iostream>
using namespace std;

class FirmData;

ostream& operator<< (ostream &, const FirmData &);
istream& operator>> (istream &, const FirmData &);

class FirmData{
    private:
        string name;
        string industry;
        string headquarterCity;
        int foundingYear;
        double revenues;
    public:
        FirmData (){
            name = {};
            industry = {};
            headquarterCity = {};
            foundingYear = {};
            revenues = {};
        }

        void setName(string input);

        void setIndustry(string input);

        void setheadQuarterCity(string input);

        void setFoundingYear(int input);

        void setRevenues(double input);

        string getName();

        string getIndustry();

        string setheadQuarterCity();

        int getFoundingYear();

        double getRevenues();

        friend ostream& operator<<(ostream &out, FirmData &obj){
            out << obj.name << endl
            << obj.industry << endl
            << obj.headquarterCity << endl
            << obj.foundingYear << endl
            << obj.revenues << endl;
            
            return out;
        }

        friend istream& operator>>(istream &input, FirmData &obj){
            getline(input, obj.name);
            getline(input, obj.industry);
            getline(input, obj.headquarterCity);
            input >> obj.foundingYear >> obj.revenues;
            input.ignore();

            return input;
        }

        bool operator==(const FirmData &right);
        bool operator!=(const FirmData &right);
};
#endif