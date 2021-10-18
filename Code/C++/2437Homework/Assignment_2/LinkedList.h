// COSC 2437 - A class template for holding a linked list.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      T value;
      struct ListNode *next;
   }; 

   ListNode *head;   // List head pointer

public:
   LinkedList()   // Constructor
      { head = nullptr; }
   ~LinkedList(); // Destructor
   void appendNode(T);
   void insertNode(T);
   void deleteNode(T);
   void displayList();
   int search(T);    // search function
   T getTotal();
   int numNodes();
   T getValueAt(int);
   T getAverage();
   T getLargest();
   int getLargestPosition();
   T getSmallest();
   int getSmallestPosition();
   T deleteLast();
   T deleteFirst();
   void insertFront(T value);
   void insertEnd(T value);
};


//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode *newNode, *nodePtr = nullptr;

   // Allocate a new node & store newValue
   newNode = new ListNode;
   newNode->value = newValue;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Find the last node in the list
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node
      nodePtr->next = newNode;
   }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

template <class T>
void LinkedList<T>::displayList()
{
	ListNode *nodePtr = nullptr;

   nodePtr = head;
   while (nodePtr)
   {
      cout << nodePtr->value << endl;
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode *newNode, *nodePtr, *previousNode = nullptr;

   // Allocate a new node & store newValue
   newNode = new ListNode;
   newNode->value = newValue;
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
	  newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Initialize nodePtr to head of list and
      // previousNode to a null pointer.
      nodePtr = head;
	  previousNode = nullptr;

      // Skip all nodes whose value member is less
      // than newValue.
	  while (nodePtr != nullptr && nodePtr->value < newValue)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
	  if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise, insert it after the prev. node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode *nodePtr, *previousNode = nullptr;

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == searchValue)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to searchValue.
	  while (nodePtr != nullptr && nodePtr->value != searchValue)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr, *nextNode = nullptr;

   nodePtr = head;
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}

//*****************************************************
// search member function                             *
//This function performs a linear search of the list. *
//*****************************************************

template <class T>
int LinkedList<T>::search(T val)
{
   int count = 1;
   ListNode *nodePtr = nullptr;

   nodePtr = head;
   while (nodePtr)
   {
      if( nodePtr->value == val)
      {
         return count;
      }
      else
      {
         nodePtr = nodePtr->next;
         count++;
      }
   }
   return 0;
}

//*************************************************
// The getTotal function returns the total of     *
// all the nodes in the list.                     *
//*************************************************
template <class T>
T LinkedList<T>::getTotal()
{
   ListNode *nodePtr = head;
   T total {};

   while(nodePtr){
      total += nodePtr->value;
      nodePtr = nodePtr->next;
   }
   return total;

}

//************************************************
// The numNodes function returns the number of   *
// nodes in the list.                            *
//************************************************
template <class T>
int LinkedList<T>::numNodes()
{
   ListNode *nodePtr = head;
   int num = 0;

   while(nodePtr){
      num++;
      nodePtr = nodePtr->next;
   }
   return num;
}

//***************************************************
// The getValueAt function returns the value stored
// at node "order". If the function receives 0, it
// returns value stored at first node, if 2 third
// node and so on.
//***************************************************
template <class T>
T LinkedList<T>::getValueAt(int order)
{
    ListNode * nodePtr = head;
    int tracker = 0;
    while(nodePtr && tracker < order){
       tracker ++;
      nodePtr = nodePtr->next;
    }

    if(tracker == order){
      return nodePtr->value;
    }
    return {};
}
//*****************************************************
// The getAverage function returns the average        *
// of the values in the list.                         *
//*****************************************************
template <class T>
T LinkedList<T>::getAverage()
{
   return getTotal()/numNodes();
}

//*************************************************
// The getLargest function returns the largest    *
// value in the list.                             *
//*************************************************
template <class T>
T LinkedList<T>::getLargest()
{
   T largest = {};
   ListNode * nodePtr = head;
   if(head){
      largest = head->value;
   }
   while(nodePtr){
      if(nodePtr->value > largest){
         largest = nodePtr->value;
      }
      nodePtr = nodePtr->next;
   }
   return largest;
}

//*************************************************
// The getLargestPosition function returns the    *
// position of the largest value in the list.     *
//*************************************************
template <class T>
int LinkedList<T>::getLargestPosition()
{
   ListNode * largest = head;
   int trackerIndex = 0;
   int position = -1;
   
   if(head){
      ListNode * nodePtr = head->next;
      position = 0;
      while(nodePtr){
         trackerIndex++;
         if(nodePtr->value > largest->value){
            largest = nodePtr;
            position = trackerIndex;
         }
         nodePtr = nodePtr->next;
      }
   }
   return position;		
}

//*************************************************
// The getSmallest function returns the smallest  *
// value in the list.                             *
//*************************************************
template <class T>
T LinkedList<T>::getSmallest()
{
  T smallest = {};
   ListNode * nodePtr = head;
   if(head){
      smallest = head->value;
   }
   while(nodePtr){
      if(nodePtr->value < smallest){
         smallest = nodePtr->value;
      }
      nodePtr = nodePtr->next;
   }
   return smallest;
}

//*************************************************
// The getSmallestPosition function returns the   *
// position of the smallest value in the list.    *
//*************************************************
template <class T>
int LinkedList<T>::getSmallestPosition()
{
   ListNode * smallest = head;
   int trackerIndex = 0;
   int position = -1;
   
   if(head){
      ListNode * nodePtr = head->next;
      position = 0;
      while(nodePtr){
         trackerIndex++;
         if(nodePtr->value < smallest->value){
            smallest = nodePtr;
            position = trackerIndex;
         }
         nodePtr = nodePtr->next;
      }
   }
   return position;
}

//Deletes last node in a list
template <class T>
T LinkedList<T>::deleteLast(){
   ListNode * nodePtr = head;
   ListNode * prvNode = nullptr;
   T val;
   if(nodePtr){
      while(nodePtr->next){
         prvNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      if(prvNode){
      val = nodePtr->value;
      prvNode->next = nullptr;
      delete nodePtr;
      }else{
         val = nodePtr->value;
         delete nodePtr;
         head = nullptr;
      }
      return val;
   }
   return -1;
}

//Deletes first node in a list
template <class T>
T LinkedList<T>::deleteFirst(){
   ListNode * nodePtr = head;
   T val = -1;
   if(head){
      head = head->next;
      val = nodePtr->value;
      delete nodePtr;
   }
   return val;
}

//INserts a node at the front of a list
template <class T>
void LinkedList<T>::insertFront(T value){
   ListNode *newNode = new ListNode;
   newNode->value = value;
   newNode->next = head;
   head = newNode;
}

//inserts a node at the end of a list
template <class T>
void LinkedList<T>::insertEnd(T value){
   ListNode *newNode = new ListNode;
   newNode->value = value;
   newNode->next = nullptr;

   ListNode *nodePtr = head;

   if(!head){
      head = newNode;
   }else{
      while(nodePtr->next){
         nodePtr = nodePtr->next;
      }
      nodePtr->next = newNode;
   }
}
#endif