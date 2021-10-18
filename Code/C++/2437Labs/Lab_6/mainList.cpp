//Lab 6

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;



struct DataType 
{
	string lastname;	// Student's Last Name
	string firstname;	// Student's First Name

	string getKey() const
	{ return lastname;
    //return firstname; 
    }   // Returns the key field

    friend ostream & operator<<(ostream &, const DataType &);
};

//---------Need to add code to overload operator <<
ostream & operator<<(ostream & out, const DataType & right){
    out << right.firstname << " " << right.lastname;
    return out;
}


//------- Need to add code to fix error: 'bool __cdecl std::operator <
//-------overload < operator

bool operator < (DataType lhs, DataType rhs)
{
    if(lhs.getKey() < rhs.getKey()){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
	ifstream studentFile ("input.txt");  // Student file
	list <DataType> students;            // Students
	DataType currStudent;              // One Student (has firstname,lastname)



	// Read each line from input.txt:
    //Store the firstname and the lastname into 
    //the temporary student structure "currStudent".
    while(studentFile >> currStudent.firstname >> currStudent.lastname){

	// Push the current student into the list ("students") 
    students.push_back(currStudent);
    }

	// Use an iterator to print the unsorted list of students.
    list<DataType>::iterator i = students.begin();
    while(i != students.end()){
        cout << *i << endl;
        i++;
    }

	// Sort the list of students.
    cout << "\nBy first name: \n"; 
    students.sort();

	// Use an iterator to print the sorted list of students.
     i = students.begin();
    while(i != students.end()){
        cout << *i << endl;
        i++;
    }
    return 0;
}