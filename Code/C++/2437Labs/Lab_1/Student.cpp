#include <string>
#include <iostream>
#include "Student.h"
using namespace std;
//Worked with Will Jamison

Student::Student(){
     name = {};
     age = {};
     weight = {};
     height = {};
}

Student::Student(string iName, int iAge, int iWeight, double iHeight){
     name = iName;
     age = iAge;
     weight = iWeight;
     height = iHeight;
}

void Student::print(){
    cout << "Name: " << name << "\n"
    << "Age: " << age << "\n"
    << "Weight: " << weight << "\n"
    << "Height: " << height << "\n\n";
}

void Student::setName(string iName){
     name = iName;
}

void Student::setAge(int iAge){
     age = iAge;
}

void Student::setWeight(int iWeight){
     weight = iWeight;
}

void Student::setHeight(double iHeight){
     height = iHeight;
}

string Student::getName(){
     return name;
}

int Student::getAge(){
     return age;
}

int Student::getWeight(){
     return weight;
}

double Student::getHeight(){
     return height;
}


