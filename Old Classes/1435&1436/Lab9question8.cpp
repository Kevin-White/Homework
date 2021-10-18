// This program displays a hot beverage menu and prompts the user to
// make a selection. A switch statement determines which item the user
// has chosen. A do-while loop repeats until the user selects item E
// from the menu.

// Kevin White

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int speed, hours, total = 0;
    
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    cout << "For how many hours has it travled? ";
    cin >> hours;
    
    
    while(speed < 0 || hours < 1){
        cout << "invalid input, try again\n\n";
        cout << "What is the speed of the vehicle in mph? ";
        cin >> speed;
        cout << "For how many hours has it travled? ";
        cin >> hours;
    }
    
    cout << endl << endl;
    cout <<"Hour    Distance Traveled in Miles\n";
    cout << "----------------------------------" << endl;
    
    for(int i = 1; i <= hours; i++){
        total = i * speed;
        cout << i << "\t\t" << total << endl << endl; 
    }
    return 0;
}