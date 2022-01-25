//Header file linkedQueue.h

#ifndef NodeType
#define NodeType

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

#endif

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue as a
// linked list.
//*************************************************************

template <class Type>
class linkedQueueType
{
	public:
		const linkedQueueType<Type>& operator=
		(const linkedQueueType<Type>&);
		//Overload the assignment operator.
		
		bool isEmptyQueue() const;
		//Function to determine whether the queue is empty.
		//Postcondition: Returns true if the queue is empty,
		//    otherwise returns false.
		
		bool isFullQueue() const;
		//Function to determine whether the queue is full.
		//Postcondition: Returns true if the queue is full,
		//    otherwise returns false.
		
		void initializeQueue();
		//Function to initialize the queue to an empty state.
		//Postcondition: queueFront = NULL; queueRear = NULL
		
		Type front() const;
		//Function to return the first element of the queue.
		//Precondition: The queue exists and is not empty.
		//Postcondition: If the queue is empty, the program
		//    terminates; otherwise, the first element of the
		//    queue is returned.
		
		Type back() const;
		//Function to return the last element of the queue.
		//Precondition: The queue exists and is not empty.
		//Postcondition: If the queue is empty, the program
		//    terminates; otherwise, the last element of the
		//    queue is returned.
		
		void addQueue(const Type& queueElement);
		//Function to add queueElement to the queue.
		//Precondition: The queue exists and is not full.
		//Postcondition: The queue is changed and queueElement is
		//    added to the queue.
		
		void deleteQueue();
		//Function  to remove the first element of the queue.
		//Precondition: The queue exists and is not empty.
		//Postcondition: The queue is changed and the first element
		//    is removed from the queue.
		
		void copyQueue(const linkedQueueType<Type>& otherQueue);
	
		
		void printQueue() const;
		// Output the content of the queue to the screen
		
		linkedQueueType();
		//Default constructor
		
		linkedQueueType(const linkedQueueType<Type>& otherQueue);
		//Copy constructor
		
		~linkedQueueType();
		//Destructor

		void linkedInsertionSort();

		void printInfo();

		void mergeSort();
		
	private:
		void mergeSort(nodeType<Type>* &head);
		nodeType<Type>* mergeList(nodeType<Type>* first1, nodeType<Type>* first2);
		void divideList(nodeType<Type>* first1, nodeType<Type>* first2);
		nodeType<Type> *queueFront; //pointer to the front of the queue
		nodeType<Type> *queueRear;  //pointer to the rear of the queue
		int comparisons;
    	int dataMoves;
};

//Default constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
} //end default constructor

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end isEmptyQueue

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;
	
	//while there are elements left in the queue
    while (queueFront != NULL)  
    {
        //set temp to point to the current node
		temp = queueFront;  
		//advance first to the next node
        queueFront = queueFront->link;
		//deallocate memory occupied by temp
        delete temp;
    }

    queueRear = NULL;  //set rear to NULL
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;
	
    newNode = new nodeType<Type>;   //create the node
	
    newNode->info = newElement; //store the info
    newNode->link = NULL;  //initialize the link field to NULL
	
    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
	
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the first node
        queueFront = queueFront->link; //advance queueFront
		
        delete temp;    //delete the first node
		
        if (queueFront == NULL) //if after deletion the queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


//Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() 
{
	initializeQueue();
} //end destructor

template <class Type>
void linkedQueueType<Type>::copyQueue (const linkedQueueType<Type>& otherQueue) 
{
	nodeType<Type> *newNode, *current, *last;
	
    if (queueFront != NULL) //if queue is nonempty, make it empty
        initializeQueue();
	
    if (otherQueue.queueFront == NULL)
        queueFront = NULL;
	else 
	{
		//set current to point to the queue to be copied
        current = otherQueue.queueFront;  
		
        queueFront = new nodeType<Type>;  //create the node
		
        queueFront->info = current->info; //copy the info
        queueFront->link = NULL;  //set the link field of the node to NULL
        last = queueFront;        //set last to point to the node
        current = current->link;  //set current to point to the next node
		
		//copy the remaining queue
        while (current != NULL) {
            newNode = new nodeType<Type>;
			
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
		
		queueRear = last;
    }//end else
}

template <class Type>
void linkedQueueType<Type>::printQueue() const {
	nodeType<Type> *temp;
	
	temp = queueFront;
	
	while(temp != NULL) {
		cout << temp->info << " ";
		temp = temp->link;
	}
}

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue) 
{
	
	if (this != &otherQueue) //avoid self-copy
        copyQueue(otherQueue);
	
    return *this;
	
} //end assignment operator

//copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) 
{
    queueFront = NULL;
    copyQueue(otherQueue);
} //end copy constructor
 
template <class Type>
void linkedQueueType<Type>::linkedInsertionSort(){
	nodeType<Type> *lastInOrder;
	nodeType<Type> *firstOutOfOrder;
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	lastInOrder = queueFront;

	if(queueFront == NULL){
		cerr << "Cannot sort an empty list." << endl;
	}else if(queueFront->link == NULL){
		cout << "The list is of length 1. It is already in order." << endl;
	}else{
		while(lastInOrder->link != NULL){
			comparisons++;
			firstOutOfOrder = lastInOrder->link;
			if (firstOutOfOrder->info < queueFront->info){
				lastInOrder->link = firstOutOfOrder->link;
				firstOutOfOrder->link = queueFront;
				queueFront = firstOutOfOrder;
				dataMoves++;
			}else{
				trailCurrent = queueFront;
				current = queueFront->link;
				while (current->info < firstOutOfOrder->info){
					comparisons++;
					trailCurrent = current;
					current = current->link;
				}
				comparisons++;
				if(current != firstOutOfOrder){
					lastInOrder->link = firstOutOfOrder->link;
					firstOutOfOrder->link = current;
					trailCurrent->link = firstOutOfOrder;
					dataMoves++;
				}else{
					lastInOrder = lastInOrder->link;

				}
			}
		}
	}
}

template <class Type>
void linkedQueueType<Type>::printInfo(){
    cout << "\nNumber Of Comparisons: " << comparisons
    <<"\nNumber Of Data Moves: " << dataMoves << endl;
}



//Merge Sort
template <class Type>
void linkedQueueType<Type>::mergeSort(){
	mergeSort(queueFront);
	if(queueFront == NULL){
		queueRear = NULL;
	}else{
		queueRear = queueFront;
		while(queueRear->link != NULL){
			queueRear = queueRear->link;
		}
	}
}

template <class Type>
void linkedQueueType<Type>::mergeSort(nodeType<Type>* &head){
	if(head == NULL || head ->link == NULL){
		return;
	}else{
		nodeType<Type> *head2;
		devideList(head, head2);
		mergeSort(head);
		mergeSort(head2);
		head = mergeList(head, head2);
	}
}

template <class Type>
nodeType<Type>* linkedQueueType<Type>::mergeList(nodeType<Type>* first1, nodeType<Type>* first2){
	comparisons++;
	if(first1 == NULL){
		return first2;
	}
	comparisons++;
	if(first2 == NULL){
		return first1;
	}
	nodeType<Type> *lastSmall;
	nodeType<Type> *newHead;

	comparisons++;
	if(first1->info < first2->info){
		dataMoves++;
		newHead = first1;
		first1 = first1->link;
	}else{
		dataMoves++;
		newHead = first2;
		first2 = first2->link;
	}
	lastSmall = newHead;

	while(first1 != NULL && first2 != NULL){
		comparisons++;
		if(first1->info < first2 ->info){
			dataMoves++;
			lastSmall->link = first1;
			first1 = first1->link;
		}else{
			dataMoves++;
			lastSmall->link = first2;
			first2 = first2->link;
		}
		lastSmall = lastSmall->link;
	}
	comparisons++;
	if(first1 == NULL){
		lastSmall->link = first2;
	}else{
		lastSmall->link = first1;
	}
	return newHead;
}

template <class Type>
void linkedQueueType<Type>::divideList(nodeType<Type>* first1, nodeType<Type>* first2){
	comparisons++;
	if(first1 == NULL || first1->link == NULL){
		first2 = NULL;
		return;
	}
	nodeType<Type> *middle;
	nodeType<Type> *current;
	middle = first1;
	current = first1->link;
	if(current != NULL){
		current = current->link;
	}

	while(current != NULL){
		middle = middle->link;
		current = current->link;

		if(current != NULL){
			current = current->link;
		}
	}

	first2 = middle->link;
	middle->link = NULL;
}


#endif
