#include <iostream>
using namespace std;

void addSort(int [], int [], const int, const int);
void sort(int [], const int);

int main(){
    int list1length = 6;
    int list2length = 3;
    int list1 [] = {11, 24, 31, 0, 0, 0};
    int list2 [] = {21, 51, 61};
    
    addSort(list1, list2, list1length, list2length);

    cout << "List 1: " << endl;
    for(int i = 0; i < list1length; i++){
        cout << list1[i] << endl;
    }


}


//Add sort finds out the length of the missing space infront of list 1 and uses it to add list 2 data into list 1
// without overflowing list 1 causing an error.

//then passes new list to sort.
void addSort(int l1 [], int l2 [], int l1length, int l2length){
    int addIndex = 0;
    while(l1[addIndex] != 0){
        addIndex++;
    }

    for(int i = 0; i < l1length - addIndex; i++){
        l1[i+addIndex] = l2[i];
    }
    sort(l1, l1length);  
}

//Sort takes a list and sorts the list
void sort(int list [], const int size){

    for (int step = 0; step < size - 1; step++) {
    int min = step;

    for (int i = step + 1; i < size; i++) {
        
      if (list[i] < list[min])
        min = i;
    }

    int temp = list[min];
    list[min] = list[step];
    list[step] = temp;
    }
}