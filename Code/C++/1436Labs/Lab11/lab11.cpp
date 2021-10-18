#include <iostream>
#include "FeetInches.h"
using namespace std;


void compare(FeetInches distance, FeetInches distance2);


int main ()
{
    FeetInches distance;
    
    cout << distance.getInches() << endl;
    
    ++distance;
    cout << distance.getInches() << endl;
    
    --distance;
    cout << distance.getInches() << endl;
    
    distance.setInches(8);
    FeetInches distance2(6, 6);
    distance += distance2;
    cout << distance << endl;
    
    compare(distance, distance2);
    
    distance.setFeet(5);
    distance.setInches(0);
    distance2.setFeet(5);
    distance2.setInches(0);
    
    compare(distance, distance2);
    
    distance.setFeet(1);
    distance.setInches(6);
    distance2.setFeet(8);
    distance2.setInches(7);
    
    compare(distance, distance2);
    
    cout << endl;
    cout << "distance: " << distance << endl;
    cout << "distance2: " << distance2 << endl;
    FeetInches distance3= distance * distance2;
    cout << "distance * distance2 = " << distance3 << endl;
    
    
    
}

void compare(FeetInches distance, FeetInches distance2){
    cout << endl;
    cout << "distance: " << distance << endl;
    cout << "distance2: " << distance2 << endl;
    cout << "distance in relation to distance2 is:" << endl;
    
    if(distance <= distance2){
        cout << "<=" << endl;
    }else{
        cout << "!(<=)" << endl;
    }
    if(distance < distance2){
        cout << "<" << endl;
    }else{
        cout << "!(<)" << endl;
    }
    if(distance > distance2){
        cout << ">" << endl;
    }else{
        cout << "!(>)" << endl;
    }
    if(distance >= distance2){
        cout << ">=" << endl;
    }else{
        cout << "!(>=)" << endl;
    }
    if(distance != distance2){
        cout << "!=" << endl;
    }else{
        cout << "!(!=)" << endl;
    }
    if(distance == distance2){
        cout << "==" << endl;
    }else{
        cout << "!(==)" << endl;
    }
}

