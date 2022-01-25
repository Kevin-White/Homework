#include<iostream>
using namespace std;


int even(int pass);

int main(){
    int test1 = 9;
    int test2 = 6;

    cout << "evens of "<< test1 << " are: " << even(test1) << endl;
    cout << "evens of "<< test2 << " are: " << even(test2) << endl;
}

int even(int pass){
    if(pass > 1){
        pass = pass - (pass % 2);
        return pass + even(pass-2);
    }
    return 0;
}