//Kevin White
#include <iostream>
using namespace std;


class Agent
{
  private:
     int listLength;
     int *list; //points to an array of listings
     double basePay;
     string name;
  public:   
    Agent(string n, double bP, int l=50);
    void setList(int value, int index); //sets a specific list's value
    void print(); //prints the agent's information and list values
};

int main(){
    Agent a1("Kevin", 50000, 5);
    
    a1.setList(0, 0);
    a1.setList(20, 1);
    a1.setList(40, 2);
    a1.setList(60, 3);
    a1.setList(80, 4);

    a1.print();
}


Agent::Agent(string n, double bP, int l){
    name = n;
    basePay = bP;
    listLength = l;
    list = new int [listLength];
}

void Agent::setList(int value, int index){
    if(index < listLength || index >= 0){
        list[index] = value;
    }
}

void Agent::print(){
    cout << name << endl
    << basePay << endl;
    for(int i = 0; i < listLength; i++){
        cout << list[i] << " ";
    }
    cout << endl;
}