// Kevin White
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct member{
    string fname;
    string lname;
    int id;
    string phone;
};

void nameSearch(const member m[], int size);
void idSearch(const member m[], int size);

int main(){
    int size = 100;
    member memberList[size];
    ifstream database;
	database.open("library_database.txt");
	int i = 0;
	int menu;
	while(database >> memberList[i].fname){
	    database >> memberList[i].lname;
	    database >> memberList[i].id;
	    database >> memberList[i].phone;
	    cout << memberList[i].fname << " " << memberList[i].lname << " " << memberList[i].id << " " << memberList[i].phone << endl;
	    i++;
	}
	database.close();
	
	do{
	cout << "Would you like to search using last name or ID?" << endl
	<< "--Menu--" << endl
	<< "1. Last Name \n2. ID\n";
	cin >> menu;
	}while(menu != 1 && menu != 2);
	
	switch(menu){
	   case 1:
	        nameSearch(memberList, size);
	        break;
	   case 2:
	        idSearch(memberList, size);
	        break;
	}
	   
}


void nameSearch(const member memberList[], int size){
    string last;
    int count = 0;
    cout << endl << "Enter a last name to search: ";
    cin >> last;
    cout << endl << "Results: " << endl;
    for(int i = 0; i < size; i++){
        if(last == memberList[i].lname){
            count++;
            cout << memberList[i].fname << " " << memberList[i].lname << " ID: " << memberList[i].id << " Phone: " << memberList[i].phone << endl;
        }else if(count > 0){
            break;
        }
    }
    if(count == 0){
        cout << "no results found";
    }
}

void idSearch(const member memberList[], int size){
    int ident;
    int count = 0;
    cout << endl << "Enter an ID to search: ";
    cin >> ident;
    cout << endl << "Results: " << endl;
    for(int i = 0; i < size; i++){
        if(ident == memberList[i].id){
            count++;
            cout << memberList[i].fname << " " << memberList[i].lname << " ID: " << memberList[i].id << " Phone: " << memberList[i].phone << endl;
            break;
        }
    }
    if(count == 0){
        cout << "no results found";
    }
}
