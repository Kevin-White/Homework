#include <iostream>
using namespace std;

void findMissing(int [], const int);

int main(){
    int size1 = 0;
    int idList1 [] = {1,2,3,4,1,2,4};
    int size2 = 0; 
    int idList2 [] = {100,33,27,89,27,99,33,99,100}; 
    
    for (int id : idList1)
	{		
		size1++;
	}
    findMissing(idList1, size1);

    for (int id : idList2)
	{		
		size2++;
	}
    findMissing(idList2, size2);
    
}



void findMissing(int idList[], const int size){
    for (int step = 0; step < size - 1; step++) {
    int min = step;
    for (int i = step + 1; i < size; i++) {
        
      if (idList[i] < idList[min])
        min = i;
        
    }
    int temp = idList[min];
    idList[min] = idList[step];
    idList[step] = temp;
    }
    
    
    for(int check = 1; check < size; check++){
    if(idList[check] != idList[check - 1]){
        cout << "ERROR: Drone " << idList[check - 1] << " Is Missing" << endl;
    }
    else{
        check++;
    }
    }
}