//********************************************************************
//Name:Kevin White
//Class: COSC 1435 Fall 20
//Instructor: Marwa Hassan
//Assignment x Problem x
//Date:10/06/2020
//Program description: WRITE what this program actually does
//*********************************************************************
#include <stdio.h>
#include <iostream>
#include<iomanip>
using namespace std;


int main()
{
    int laptopNum;
    double total, discountPre, discountNum, profit, cost;
    
    //asks user for number of laptops and stores the number
    cout << "how many laptops\n";
    cin >> laptopNum;
    
    if(laptopNum > 0){
    // finds discount if any
    if(laptopNum < 10){
        discountPre = 0;
    }
    else if(laptopNum < 20){
        discountPre = 0.1;
    }
    else if(laptopNum < 30){
        discountPre = 0.15;
    }
    else if(laptopNum < 40){
        discountPre = 0.2;
    }
    else {
        discountPre = 0.25;
    }
    
    //Calculating Order Total, Total Discount and Total Profit
    total = laptopNum * 3500;
    discountNum = total * discountPre;
    total = total - discountNum;
    cost = laptopNum * 2000;
    profit = total - cost;
    
    //Display info for user
    cout << setprecision(2) << fixed;
    cout << "Oder Total: $" << total << endl;
    cout << "Total Discount: $" << discountNum << endl;
    cout << "Total Profit: $" << profit << endl;
    
        
    }
    else
    {
        cout << "Invalid input";
    }
}
