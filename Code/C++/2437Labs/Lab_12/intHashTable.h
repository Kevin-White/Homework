// integer hash table

#include<iostream>
#include<iomanip>
using namespace std;

const int DEFAULT_TABLE_SIZE = 17;

class intHashTable
{
	public:
		~intHashTable();
		intHashTable(int parameterSize = DEFAULT_TABLE_SIZE);
		int hashFunc(int);
		int add(int);
		//bool search(int);
		void print();

	private:
		int *arr;
		int arrSize;
};

// Destructor
intHashTable::~intHashTable()
{
	delete [] arr;
}

// Constructor
intHashTable::intHashTable (int parameterSize)
{
	if (parameterSize < 1)
	{
		cout << "Size of the hash table must be positive." << endl;
		cout << "Creating a hash table of size " << DEFAULT_TABLE_SIZE << "." << endl;
		arrSize = DEFAULT_TABLE_SIZE;
	}
	else
		arrSize = parameterSize; //set hash table size to parameter

	// declare the array
	arr = new int[arrSize];

	// initialize all array elements to -1
	for(int i = 0; i < parameterSize; i++){
        arr[i] = -1;
	}

}

//---------------------------------------------------
// hashFunc
// Based on the value of new element, determine its index
//---------------------------------------------------
int intHashTable::hashFunc(int newVal)
{
	// use modulo-division hashing
	return newVal % arrSize;

}

//---------------------------------------------------
// add
// Adds a new node to the intHashTable
// Collisions are resolved by linear probing.
//---------------------------------------------------
int intHashTable::add(int newVal) {

	int pos = hashFunc(newVal);
	int coll = 0;
	if(arr[pos] == -1){
	    // No collision
            arr[pos] = newVal;
	}else{
        // Collision found - resolve by linear probing

        while(arr[pos] != -1){
            pos = (pos + 1) % arrSize;
            coll++;
        }
        arr[pos] = newVal;
	}


	return coll;
}

//---------------------------------------------------
// search
// Searches through the intHashTable for 'key'.
// Returns true if found and false otherwise
//---------------------------------------------------

/*
bool intHashTable::search(int key)
{
	// Get the node address
	int pos = hashFunc(key);

	// while(???)
	{
		// index is empty, quit
		if(arr[pos] == -1)
			return false;

		// Element is found
		if(arr[pos] == key)
			return true;

		// Collision - how to increment??
		//pos = ???
		num_collisions++;
	}

	// return ???;
}
*/

//---------------------------------------------------
// Outputs the entire list to the screen
//---------------------------------------------------
void intHashTable::print()
{
	for(int i = 0; i < arrSize; i++)
		cout << setw(3) << i << ": " << setw(6) << arr[i] << endl;

	return;
}
