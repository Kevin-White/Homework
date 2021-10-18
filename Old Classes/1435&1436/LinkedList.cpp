// Implementation file for the LinkedList class
#include <iostream>  
#include "LinkedList.h"
using namespace std;


//**************************************************
// constructor								       *
//**************************************************
LinkedList::LinkedList()
{
	
	// initilize the head to null
		head = nullptr;
}

//**************************************************
// appendNode function creates and appends
// a node with the passed value
//**************************************************
void LinkedList::appendNode(double num)
{
 ListNode *newNode;
 newNode = new ListNode;
 newNode->value = num;
 newNode->next = nullptr;
 
  ListNode *nodePtr;
  
  if(!head){
      head = newNode;
  }else{
      nodePtr = head;
      while(nodePtr->next){
          nodePtr = nodePtr->next;
      }
      
      nodePtr->next = newNode;
  }
}

//**************************************************
// deleteNode function searches for and deletes
// the node containing the passed value
//**************************************************

void LinkedList::deleteNode(double num)
{
    ListNode *nodePtr;
    ListNode *prevNode;
    
    if(!head){
        return;
    }
    
    if(head->value == num){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        nodePtr = head;
        
        while(nodePtr != nullptr && nodePtr->value != num){
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(nodePtr){
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// displayList displays the values stored in each
// node in the list
//**************************************************

void LinkedList::displayList() const
{
  ListNode *nodePtr;
  nodePtr = head;
  
  while(nodePtr){
      cout << nodePtr->value << " ";
      nodePtr = nodePtr->next;
  }
}



//**************************************************
// The insertNode puts in a node before a number biger than it.
//**************************************************
void LinkedList::insertNode(double num){
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *preNode;
    
    newNode = new ListNode;
    newNode->value = num;
    
    if(!head){
        head = newNode;
        newNode->next = nullptr;
    }else{
        nodePtr = head;
        preNode = nullptr;
        
        while(nodePtr != nullptr && nodePtr->value < num){
            preNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(preNode == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        }else{
            preNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


//**************************************************
// The length returns length of linked list.
//**************************************************
int LinkedList::length(){
    ListNode *nodePtr;
    
    int count = 0;
    
    if(!head){
        return count;
    }else{
      nodePtr = head;
      count++;
      while(nodePtr->next){
          nodePtr = nodePtr->next;
          count++;
      }
      return count;
    }
}

//**************************************************
// Fnkds index of the number in linked list
//**************************************************
int LinkedList::findOrder(double num){
    ListNode *nodePtr;
    int count = 0;

    if(!head){
        return -1;
    }
    
    if(head->value == num){
        return count;
    }else{
        nodePtr = head;
        count ++;
        while(nodePtr != nullptr && nodePtr->value != num){
            nodePtr = nodePtr->next;
            count++;
        }
        if(nodePtr){
            return count;
        }
    }
    return -1;
}

//**************************************************
// Puts number in user specified location
//**************************************************
void LinkedList::insertAt(double num, int location){
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *preNode;
    
    int count = 0;
    
    newNode = new ListNode;
    newNode->value = num;
    
    if(!head){
        head = newNode;
        newNode->next = nullptr;
    }else{
        nodePtr = head;
        preNode = nullptr;
        count ++;
        
        while(nodePtr != nullptr && count < (location + 1)){
            preNode = nodePtr;
            nodePtr = nodePtr->next;
            count++;
        }
        
        if(preNode == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        }else{
            preNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


//**************************************************
// removes number in user specified location
//**************************************************
void LinkedList::removeAt(int location){
    ListNode *nodePtr;
    ListNode *prevNode;
    
    int count = 0;
    
    if(!head){
        return;
    }else{
        nodePtr = head;
        count++;
        while(nodePtr != nullptr && count < (location + 1)){
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            count++;
        }
        
        if(nodePtr){
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// The Destructor deletes every node in the list
//**************************************************
LinkedList::~LinkedList()
{
    ListNode *nodePtr;
    ListNode *nextNode;
    
    nodePtr = head;
    
    while(nodePtr != nullptr){
        nextNode = nodePtr->next;
        
        delete nodePtr;
        
        nodePtr = nextNode;
    }
}