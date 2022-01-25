//********************************************************************
//Name:Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 2 Problem 2
//Date:2/12/2021
//Program description: This program gets files and puts them into different vectors and uses searching algorithms to find info in the vectors.
//*********************************************************************
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int binarySearch(const vector<string>, int , string);
void fillVector(vector<string> &, int &, string);

int main()
{
    vector<string> teams;
    int teamSize = 0;
    vector<string> winners;
    int winnerSize = 0;
    vector<string> losers;
    int loserSize = 0;
    vector<string> years;
    int yearSize = 0;
    vector<int> teamData;
    int teamDataSize = 0;
    
    int temp;
    string str;
    
    cout << "Team Names: \n";
    fillVector(teams, teamSize, "teams.txt");
    for(int i = 0; i < teamSize; i++){
        cout << teams[i] << endl;
    }    

    cout << "\nEnter a team name: ";
    getline(cin, str);
    while(binarySearch(teams, teamSize, str) == -1){
        cout << "team is not in list, try again: ";
        getline(cin, str);
    }
    
    fillVector(winners, winnerSize, "winners.txt");
    for(int i = 0; i < winnerSize; i++){
        if(!winners[i].compare(str)){
            teamData.push_back(i);
            teamDataSize++;
        }
    }
    cout << endl << str << " have won " << teamDataSize << " time(s)" << endl;
    
    cout << "Years Won\tTeams Beat" << endl; 
    fillVector(years, yearSize, "years.txt");
    fillVector(losers, loserSize, "losers.txt");
    for(int i = 0; i< teamDataSize; i++){
        cout << years[teamData[i]] << "\t\t" << losers[teamData[i]] << endl;
        
    }
    
    cout << endl << endl << "Enter a year the World Series was played: ";
    cin >> str;
    temp = binarySearch(years, yearSize, str);
    while(temp == -1){
        cout << "The World Series was not played that year. Try again: ";
        cin >> str;
        temp = binarySearch(years, yearSize, str);
    }
    cout << "The " << winners[temp] << " won that year!";
    
}


// fillVector function
// This function fills the vector given with the file given and keeps track of its size.
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector<string> &vec    A vector that the function can eddit the content of.
// int &size              The size of the vector that the functin can edit directly
// string fileName        The name of the file you want to pull from to eddit the vector
//*************************************************

void fillVector(vector<string> &vec, int &size, string fileName){
    fstream inFile;
    inFile.open(fileName);
    string str;
    
    while(getline(inFile, str)){
        vec.push_back(str);
        size++;
    }
    
    inFile.close();

}
// binarySearch function
// This function will try to find a target inside of a vector through binarySearch
//
// Return Value
// ------------
// int  the index of the value if found or -1
//
// Parameters
// ------------
// const vector<string> vec    A vector that the function can't edit only look through 
// int size                    the size of the vector to help the algorithm function properly
// string target               the target we are looking for inside of the function.
//*************************************************
int binarySearch(const vector<string> vec, int size, string target){
    int first = 0;
    int last = size -1;
    while(last >= first){
        int mid = (first + last)/2;
        if(!vec[mid].compare(target)){
            return mid;
        }else if(vec[mid] > target){
            last = mid -1;
        }else if(vec[mid] < target){
            first = mid + 1;
        }
    }
    return -1;
}
