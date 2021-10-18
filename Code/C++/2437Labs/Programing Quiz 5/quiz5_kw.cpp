//Name:
#include<iostream>
using namespace std;
class List
{
private:
    struct ListNode
    {
        int value;              // value in this node
        struct ListNode *next;  // point to next node
    };
    ListNode *head;            // List head pointer
public:
    //class member function definitions
    List()   // Constructor
    { head = nullptr; }
    void appendNode(int newValue)
    {
        ListNode *newNode, *nodePtr = nullptr;
        newNode = new ListNode;
        newNode->value = newValue;
        newNode->next = nullptr;
        if (!head)
            head = newNode;
        else
        {
            nodePtr = head;
            while (nodePtr->next)
                nodePtr = nodePtr->next;
            nodePtr->next = newNode;
        }
    }
    void displayList() const
    {
        ListNode *nodePtr;
        nodePtr = head;
        while (nodePtr)
        {   cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout<<endl;
    }
    void updateNode(int order, int newValue)
    {
        ListNode *nodePtr = head;
        while(nodePtr){
            if(order == 1){
                nodePtr->value = newValue;
                break;
            }else{
                nodePtr = nodePtr->next;
                order--;
            }
        }
    }
};

int main()
{
    List test;
    test.appendNode(22);
    test.appendNode(34);
    test.appendNode(57);
    cout << "List:\n";
    test.displayList();

    test.updateNode(2, 41);
    cout << "List After updateNode:\n";
    test.displayList();
    
    return 0;
}