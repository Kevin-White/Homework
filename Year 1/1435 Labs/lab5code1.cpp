#include <iostream>
using namespace std;

int main()
{
	int currentYear = 2020;
	int yearBorn;
	int age;
	
	//Program Code
	cout<< "***Age Calculator Program***"; //print title
	cout << endl << endl; //Print 2 blank lines
	
	cout<< "What year where you born: ";
	cin >> yearBorn;
	age = currentYear - yearBorn;
	
	cout << "You are " << age << " years old!";
	cout << endl << endl;
	
	return 0;
	

}

