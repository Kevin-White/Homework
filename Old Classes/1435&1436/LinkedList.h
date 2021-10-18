#ifndef LinkedList_H
#define LinkedList_H

class LinkedList
{
private:
   // Declare the node structure
   struct ListNode{
       double value;
       struct ListNode *next;
   };
   // Declare the head pointer
   ListNode *head;

public:
   // Constructor
   LinkedList();
      
   // Destructor
   ~LinkedList();
      
   // Linked list operations
   void appendNode(double);
   void deleteNode(double);
   void displayList() const;
   void insertNode(double num);
   int length();
   int findOrder(double num);
   void insertAt(double num, int location);
   void removeAt(int location);
};
#endif