//********************************************************************
//Name: Kevin White
//Class: COSC 1435 Spring 21
//Instructor: Marwa Hassan
//Assignment 1 Problem 2
//Date: 1/30/2021
//Program description: Finds the % of a certent grade in a list
//*********************************************************************


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("grades.txt");
    vector<char> scores;
    char hold;
    double count;
    
    while(inFile >> hold){
        scores.push_back(hold);
    }
    cout << "The number of grades in file is: " << scores.size() << endl
    << "-----------------------------------------------------" << endl;
    while(hold != 'q'){
        count = 0;
        cout << "Please enter a letter grade category A B C D or F (q to quit): ";
        cin >> hold;
            while(!(hold >= 'A' && hold <='D') && !(hold == 'F' || hold == 'q')){
               cout <<  "Invalid! Please enter a valid letter grade: ";
               cin >> hold;
               
            }
            
            if(hold != 'q'){
                for(int i = 0; i < scores.size(); i++){
                    if(hold == scores[i]){
                        count++;
                    }
                }
                cout << "\nNumber of "<< hold << "s in file = " << count << " that is " << setprecision(4) << (count/scores.size()) * 100 << "%" << endl
                << "-----------------------------------------------------" << endl;
            }
    
    }
    
    cout << "Thank you!";
}
