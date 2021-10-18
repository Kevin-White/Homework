//Write your name here

#include <iostream>

#include <iomanip>

using namespace std;

 

//function prototypes
double ftoc(double);
double ctof(double);

int main()

{
    int pick;
    double temp;
    cout << "enter a temperature: ";
    cin >> temp;
    cout << "1. Change F to C\n"
    << "2. Change C to F\n";
    cin >> pick;
    
    switch(pick){
    case 1: 
        temp = ftoc(temp);
        cout << "Your temp in C: " << temp;
        break;
    case 2:
        temp = ctof(temp);
        cout << "Your temp in F: " << temp;
        break;
        
    }
    
}

double ftoc(double f){
    return (f - 32) * 5/9; 
}
double ctof(double c){
    return (c * 9/5 ) + 32;
}
