//********************************************************************
//Name: Kevin White
//Class: COSC 1435 Fall 20
//Instructor: Marwa Hassan
//Assignment x Problem x
//Date:10/06/2020
//Program description: trys to help user fix wifi connection
//*********************************************************************
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    char answer;
    cout << "Reboot the computer and try to connect.\n Did that fix the problem? (y/n): ";
    cin >> answer;
    if(answer == 'n'){
        cout << "Reboot the router and try to connect.\n Did that fix the problem? (y/n): ";
        cin >> answer;
        if(answer == 'n'){
            cout << "Make  sure the cables between the router and modem are plugged in firmly.\n Did that fix the problem? (y/n): ";
            cin >> answer;
            if(answer == 'n'){
                cout << "Move the router to a new location and try to connect.\n Did that fix the problem? (y/n): ";
                cin >> answer;
                if(answer == 'n'){
                    cout << "Get a new router\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yay problem solved!";
    return 0;
}

