#include <iostream>
using namespace std;

class Number{
    private:
        int num;

    public:
        Number();
        Number(const int);
        int getValue();
        Number getNext();
        Number getPrevious();
};

int main(){
    Number test(13);
    Number nextTest = test.getNext();
    Number previousTest = test.getPrevious();

    cout << previousTest.getValue() << endl
    << test.getValue() << endl
    << nextTest.getValue() << endl; 
}





Number::Number(){
    num = 1;
}

Number::Number(int n){
    num = n;
}

int Number::getValue(){
    return num;
}

Number Number::getNext(){
    Number temp(num + 1);
    return temp;
}

Number Number::getPrevious(){
    Number temp(num - 1);
    return temp;
}