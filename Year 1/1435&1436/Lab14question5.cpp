//Write your name here

#include <iostream>
#include<iomanip>

using namespace std;

 

//function prototyp
int highest(int []);
int lowest(int []);
int getTotal(int []);

int main(){
    string flavors[6] =  {"cherry", "cinnamon", "licorice", "orange", "coconut", "cotton candy"};
    int bags [6];
    int high, low, total;
    for(int i = 0; i < 6; i++){
        cout << "Bags sold of " << left << setw(12) << flavors[i] << ":  ";
        cin >> bags[i];
        while(bags[i] < 0){
            cout << "Enter a positive number: ";
            cin >> bags[i];
        }
    }
    
    cout <<  left << setw(12) <<"Flavor" << "\t" << "Bags Sold" << endl
    << "____________________________"<< endl;
    for(int i = 0; i < 6; i++){
        cout <<  left << setw(12) << flavors[i] << "\t" << bags[i] << endl;
    }
    cout << endl;
    high = highest(bags);
    cout << "Highest Seller: " << flavors[high] << " with sales " << bags[high] << endl;
    low = lowest(bags);
    cout << "Lowest Seller : " << flavors[low] << " with sales " << bags[low] << endl;
    total = getTotal(bags);
    cout << "Total Sales: " << total;
}

int highest(int bags[]){
    int hold = 0;
    for(int i = 1; i < 6; i++){
        if(bags[hold] < bags[i]){
            hold = i;
        }
    }
    return hold;
}

int lowest(int bags[]){
    int hold = 0;
    for(int i = 1; i < 6; i++){
        if(bags[hold] > bags[i]){
            hold = i;
        }
    }
    return hold;
}

int getTotal(int bags[]){
    int sum = 0;
    for(int i = 0; i < 6; i++){
        sum += bags[i];
    }
    return sum;
}
 

