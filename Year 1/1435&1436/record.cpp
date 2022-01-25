//********************************************************************
//Name: Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 6 Problem 1
//Date: 3/24/2021
//Program description: Takes information from student.dat gives you info about GPA
//*********************************************************************

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

enum classCode{FRESHMAN = 1, SOPHOMORE = 2, JUNIOR = 3, SENIOR = 4};
enum {Business = 1, Liberal_Arts = 2, Engineering = 3};

struct Student{
  int SSN;
  string name;
  int year;
  int code;
  double GPA;
  int credits;
};

void fillList(vector<Student> & list);
void allGPA(vector<Student> list);
void schoolGPA(vector<Student> list);
void hundoCredits(vector<Student> list);
void classGPA(vector<Student> list);

int main(){
    vector<Student> list;
    fillList(list);
    allGPA(list);
    schoolGPA(list);
    hundoCredits(list);
    classGPA(list);

    
}
//*************************************************
// fillList function
// This function fills a vector from data form student.dat
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector<Student> & list:  The list where all the data from student.dat is stored.
//*************************************************

void fillList(vector<Student> & list){
    ifstream data;
    data.open("students.dat");
    Student hold;
    while(data >> hold.SSN){
        data >> hold.name >> hold.year >> hold.code >> hold.GPA >> hold.credits;
        list.push_back(hold);
    }
}
//*************************************************
// allGPA function
// This function displays percentage of students within a GPA range
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector<Student> & list: The list data is taken from that determons where the students go in the GPA range
//*************************************************
void allGPA(vector<Student> list){
    double low = 0, mid = 0, high = 0;
    for(int i = 0; i < list.size(); i++){
        if(list[i].GPA <2.0){
            low++;
        }else if(list[i].GPA > 3.0){
            high++;
        }else{
            mid++;
        }
    }
    cout << "a. The percentage of students with a GPA of:" << endl
    << "\t1. less than 2.0:\t\t" << 100*(low/list.size()) << "%"  << endl
    << "\t2. between 2.0 and 3.0:\t\t" << 100*(mid/list.size()) << "%" << endl
    << "\t3. greater than 3.0:\t\t" << 100*(high/list.size()) << "%"  << endl;
}

//*************************************************
// schoolGPA function
// This function displays percentage of students that have a larger than 3.0 GPA based on school
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector<Student> & list: The list data is taken from to see if students have a higher than 3.0 GPA and if to see what school they are in
//*************************************************
void schoolGPA(vector<Student> list){
    double bus = 0, lib = 0, eng = 0;
    for(int i = 0; i < list.size(); i++){
     if(list[i].GPA > 3.0 && list[i].code == Business){
         bus++;
     }else if(list[i].GPA > 3.0 && list[i].code == Liberal_Arts){
         lib++;
     }else if(list[i].GPA > 3.0 && list[i].code == Engineering){
         eng++;
     }        
    }
    cout << "b. The percentage of students with GPAs greater than 3.0 who are:" << endl
    << "\t1. Business majors:\t\t" << 100*(bus/list.size()) << "%"  << endl
    << "\t2. Liberal Arts majors:\t\t" << 100*(lib/list.size()) << "%" << endl
    << "\t3. Engineering majors:\t\t" << 100*(eng/list.size()) << "%"  << endl;
}

//*************************************************
// hundoCredits function
// This function displays percentage of students with 100 credits and less than 2.0 GPA
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector<Student> & list: The list data that tells us if student has more than 100 credits and less than 2.0 GPA
//*************************************************
void hundoCredits(vector<Student> list){
    double num = 0;
    for(int i = 0; i < list.size(); i++){
     if(list[i].credits > 100 && list[i].GPA < 2.00){
         num++;
     }   
    }
    cout << "c. The percentage of students who have earned more" << endl
    << "\tthan 100 credits and have GPAs less than 2.00:\t" << 100*(num/list.size()) << "%"  << endl;
}

//*************************************************
// classGPA function
// This function displays percentage of students with a 3.0 GPA based on Class/Year
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector<Student> & list: The list data is taken from that tell us what year the students are in and if they have over a 3.0 GPA
//*************************************************
void classGPA(vector<Student> list){
    double fr = 0, so = 0, ju = 0, se= 0;
    for(int i = 0; i < list.size(); i++){
     if(list[i].GPA > 3.0 && list[i].year == FRESHMAN){
         fr++;
     }else if(list[i].GPA > 3.0 && list[i].year == SOPHOMORE){
         so++;
     }else if(list[i].GPA > 3.0 && list[i].year == JUNIOR){
         ju++;
     }else if(list[i].GPA > 3.0 && list[i].year == SENIOR){
         se++;
     }        
    }
    cout << "b. The percentage of students with GPAs greater than 3.0 who are:" << endl
    << "\t1. Freshmen:\t\t\t" << 100*(fr/list.size()) << "%"  << endl
    << "\t2. Sophomores:\t\t\t" << 100*(so/list.size()) << "%" << endl
    << "\t3. Juniors:\t\t\t" << 100*(ju/list.size()) << "%"  << endl
    << "\t3. Seniors:\t\t\t" << 100*(se/list.size()) << "%"  << endl;
}
