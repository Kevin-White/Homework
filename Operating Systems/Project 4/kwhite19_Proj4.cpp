#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

ifstream input;

void printResource(int r){
    for(int i = 0; i < r; i++){
        cout << char(i+65) << " ";
    }
    cout << endl;
}

void printAndStore(int **, int, int);
bool isSafe(int **, int **, int[], int, int);

int main(int argc, char *argv[]){
    string fileName = argv[1];
    
    input.open(fileName.c_str());
    
    int processNum;
    input >> processNum;
    cout << "There are " << processNum << " processes in the system." << endl << endl;
    
    int resourceNum;
    input >> resourceNum;
    cout << "There are " << resourceNum << " resource types." << endl << endl;
    int RESOURCE = resourceNum;
    
    int** allocation = new int*[processNum];
    int** max = new int*[processNum];
    int** need = new int*[processNum];
    
    for(int i = 0; i < processNum; i++){
        allocation[i]=new int[resourceNum];
        max[i]=new int[resourceNum];
        need[i]=new int[resourceNum];
    }
    
    cout << "The Allocation Matrix is...\n   ";
    printResource(resourceNum);
    printAndStore(allocation, processNum, resourceNum);

    cout << "The Max Matrix is...\n   ";
    printResource(resourceNum);
    printAndStore(max, processNum, resourceNum);

    cout << "The Need Matrix is...\n   ";
    printResource(resourceNum);

    for(int i = 0; i < processNum; i++){
        cout << i << ": ";
        for(int j = 0; j < resourceNum; j++){
            int hold;
            hold = max[i][j] - allocation[i][j];
            need[i][j] = hold;
            cout << hold << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    int available[resourceNum];
    
    cout << "The Available Vector is...\n";
    printResource(resourceNum);

    for(int i = 0; i < resourceNum; i++){
        int hold;
        input >> hold;
        available[i] = hold;
        cout << hold << " ";
    }
    cout << endl << endl;
    
    if(isSafe(allocation, need, available, processNum, resourceNum)){
     cout << "THE SYSTEM IS IN A SAFE STATE!" << endl << endl;
    }else{
        cout << "THE SYSTEM IS NOT IN A SAFE STATE!" << endl << endl;
    }
    
    int request[resourceNum];
    
    cout << "The Request Vector is...\n   ";
    printResource(resourceNum);
    
    string FinHold;
    getline(input, FinHold);
    getline(input, FinHold);
    getline(input, FinHold);
    cout << " " << FinHold << endl << endl;
    FinHold.erase(0,2);
    stringstream ss;
    ss << FinHold;
    for(int i = 0; i < resourceNum; i++){
        ss >> request[i];
    }
    
    
    bool granted = true;
    
    for(int i = 0; i < resourceNum; i++){
        if((available[i] - request[i]) < 0){
            granted = false;
        }
    }
    
    if(granted){
        cout << "THE REQUEST CAN BE GRANTED!" << endl << endl;
        
        cout << "The Available Vector is...\n";
    printResource(resourceNum);
    for(int i = 0; i < resourceNum; i++){
        cout << available[i] - request[i] << " ";
    }
    cout << endl;
    }else{
        cout << "THE REQUEST CAN NOT BE GRANTED!" <<endl;
    }
    
}

void printAndStore(int **arr, int pro, int res){
    for(int i = 0; i < pro; i++){
        cout << i << ": ";
        for(int j = 0; j < res; j++){
            int hold;
            input >> hold;
            arr[i][j] = hold;
            cout << hold << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **allocation, int **need, int available[], int processNum, int resourceNum){
    int holdAvailable[resourceNum];
    bool finishRequest[processNum];
    for(int i = 0; i < resourceNum; i++){
        holdAvailable[i] = available[i];
    }
    for(int i = 0; i < processNum; i++){
        finishRequest[i] = false;
    }
    
    for(int i = 0; i < processNum; i++){
        for(int j = 0; j < processNum; j++){
            bool pass = true;
            if(!finishRequest[j]){
                for(int k = 0; k < resourceNum; k++){
                    if(need[j][k] > holdAvailable[k]){
                        pass = false;
                    }
                }
            if(pass){
                finishRequest[j] = true;
                for(int k = 0; k < resourceNum; k++){
                    holdAvailable[k] += allocation[j][k];
                }
            }
            }
        }
    }
    
    for(int i = 0; i < processNum; i++){
        if(!finishRequest[i]){
            return false;
        }
    }
    return true;
}
