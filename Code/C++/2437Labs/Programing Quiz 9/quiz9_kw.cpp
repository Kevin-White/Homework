//Kevin White

#include <iostream>

using namespace std;

 

class LinkedList

{

private:

    struct Node

    {

        Node* next;

        int data;

    };

    Node* head;

public:

    LinkedList()

    {head = NULL;}

    void insert(int data);

    void print();

    void splitAt(LinkedList&, int );

};

 

void LinkedList::insert(int data){

    Node* node = new Node();

    node->data = data;

    node->next = head;

    head = node;

}

 

void LinkedList::print(){

    Node* temp = head;

    while(temp){

        cout <<temp->data << " ";

        temp = temp->next;

    }

    cout<<endl;

}

 

void LinkedList::splitAt(LinkedList &secondList, int value)

{
    Node* track = head;
    Node* trackFollow;
    while(track->data != value && track != NULL){
        trackFollow = track;
        track = track->next;
    }
    if(track == NULL){
        return;
    }else{
        secondList.head = track;
        trackFollow->next = NULL;
    }

}

 

int main()

{

    LinkedList list;

    LinkedList secondList;

    //insert values into list then display it
    list.insert(50);
    list.insert(40);
    list.insert(20);
    list.insert(16);
    list.insert(68);

    cout << "Full List:\n";
    list.print();
    //call the function and display the two lists
    list.splitAt(secondList, 20);
    cout << "\nList One:\n";
    list.print();
    cout << "\nList Two:\n";
    secondList.print();

    return 0;

}