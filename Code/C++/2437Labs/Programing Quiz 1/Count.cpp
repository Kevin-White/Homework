#include <iostream>
using namespace std;

class Counter{
    private:
        int count;

    public:
        Counter();
        void increment();
        int getCount();

};

int main(){
    Counter z;
    int input = 0;
    
    cout << "Enter Numbers, or -99 to end program" << endl;

    while( input != -99){
        cout << "Enter a number: ";
        cin >> input;
        if(input == 0){
            z.increment();
        }
    }

    cout << "you input: " << z.getCount() << " Zeros";

}







Counter::Counter(){
    count = 0;
}

void Counter::increment(){
    count++;
}

int Counter::getCount(){
    return count;
}