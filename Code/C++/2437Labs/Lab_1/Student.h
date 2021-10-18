#ifndef Student_H
#define Student_H

#include <string>
#include <iostream>
using namespace std;
//Worked with Will Jamison

class Student
{
    private:
        string name;
        int age;
        int weight;
        double height;
    
    public:
        Student();
        Student(string, int, int, double);
        void print();
        void setName(string);
        void setAge(int);
        void setWeight(int);
        void setHeight(double);
        string getName();
        int getAge();
        int getWeight();
        double getHeight();
        

};
#endif