//Header file: myStack.h

#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operation on a stack as an 
// array.
//*************************************************************

template <class T>
class stackType: public stackADT<T>
{
private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    T *list; //pointer to the array that holds the stack elements
    
    void copyStack(const stackType<T>& otherStack);
    //Function to make a copy of otherStack.
    //Postcondition: A copy of otherStack is created and assigned
    //    to this stack.
public:
    stackType(int stackSize = 100);
    //Constructor
    //Create an array of the size stackSize to hold
    //the stack elements. The default stack size is 100.
    //Postcondition: The variable list contains the base address
    //   of the array, stackTop = 0, and maxStackSize = stackSize
    
    stackType(const stackType<T>& otherStack);
    //Copy constructor
    
    ~stackType();
    //Destructor
    //Remove all the elements from the stack.
    //Postcondition: The array (list) holding the stack
    //    elements is deleted.
    
    const stackType<T>& operator=(const stackType<T>&);
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0;

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //    otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //    otherwise returns false.

    void push(const T& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem is
      //    added to the top of the stack.

    T top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //    terminates; otherwise, the top element of the stack
      //    is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top element is
      //    removed from the stack.


    
};

template <class T>
void stackType<T>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

template <class T>
bool stackType<T>::isEmptyStack() const
{
    return(stackTop == 0);
}//end isEmptyStack

template <class T>
bool stackType<T>::isFullStack() const
{
    return(stackTop == maxStackSize);
} //end isFullStack

template <class T>
void stackType<T>::push(const T& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the 
                                    //top of the stack
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

template <class T>
T stackType<T>::top() const
{
    assert(stackTop != 0);          //if stack is empty, 
                                    //terminate the program
    return list[stackTop - 1];      //return the element of the
                                    //stack indicated by 
                                    //stackTop - 1
}//end top

template <class T>
void stackType<T>::pop()
{
    if (!isEmptyStack())
        stackTop--;                 //decrement stackTop 
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class T>
stackType<T>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to 
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new T[maxStackSize];  //create the array to
                                    //hold the stack elements
}//end constructor

template <class T>
stackType<T>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied 
                    //by the array
}//end destructor

template <class T>
void stackType<T>::copyStack(const stackType<T>& otherStack)
{ 
    delete [] list;				   
    maxStackSize = otherStack.maxStackSize;		   
    stackTop = otherStack.stackTop;			   
	  
    list = new T[maxStackSize];

        //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
} //end copyStack


template <class T>
stackType<T>::stackType(const stackType<T>& otherStack)
{
    list = NULL;

    copyStack(otherStack);
}//end copy constructor

template <class T>
const stackType<T>& stackType<T>::operator=
   					(const stackType<T>& otherStack)
{ 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
} //end operator=         

#endif