#include <string>
#include <iostream>
#include "Student.h"
using namespace std;
//Worked with Will Jamison


int main(){
    Student stu1("Kevin Right", 19, 135, 5.83);
    cout << "Student Bio:" << endl;
    stu1.print();

    cout << "Name " << stu1.getName() << " is wrong!" << endl;

    stu1.setName("Kevin White");

    cout << "New Name is: " << stu1.getName() << endl << endl;

    cout << "New Student Bio:" << endl;
    stu1.print();



}