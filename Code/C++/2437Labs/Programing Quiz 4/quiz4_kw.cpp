//Kevin White
#include <iostream>
using namespace std;
class Node
{
public:
 int Data;
 Node * Next;
};
int main()
{
 // Create nodes
 Node * a = new Node;
 Node * b = new Node;
 Node * c = new Node;
 a->Data = 37;
 b->Data = 16;
 c->Data = 25;
    
 // Connect the nodes
 a->Next = b;
 a->Next->Next = c;
 a->Next->Next->Next = NULL;
    
//Display values in the list
 cout<<a->Data<<" "<<a->Next->Data<<" "<<a->Next->Next->Data<<endl;
    
//swap the second and third nodes in the list by adjusting only the links (not the data).
a->Next = c;
c->Next = b;
b->Next = NULL;




//Display the modified list
cout<<a->Data<<" "<<a->Next->Data<<" "<<a->Next->Next->Data<<endl;

 return 0;
}
