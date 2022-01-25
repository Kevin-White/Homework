#include <string>
#include <iostream>
#include <fstream>
#include "intHashTable.h"

int main(){
    fstream inFile( "lab12data.txt" );
    int hold;
    intHashTable test(13);
    while(inFile >> hold){
        int coll = test.add(hold);
        cout << hold << " had " << coll << " collisions\n";
    }
    test.print();

}
