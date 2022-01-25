
// Simulates the flow of customers through a line in a store.
// Lab 10 - 2437

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "linkedQueue.h"

using namespace std;

int main ()
{
	LinkedQueue<int> line;      // Line (queue) of customers containing the
	//   time that each customer arrived and
	//   joined the line
	int simLength,         // Length of simulation (minutes)
		minute,            // Current minute
		timeArrived,       // Time dequeued customer arrived
		waitTime,          // How long dequeued customer waited
		totalServed = 0,   // Total customers served
		totalWait   = 0,   // Total waiting time
		maxWait     = 0,   // Longest wait
		numArrivals = 0;

	cout << endl << "Enter the length of time to run the simulator: ";
	cin >> simLength;

	srand(time(0));
	for ( minute = 0 ; minute < simLength ; minute++ )
	{
		if ( !line.isEmptyQueue())
		{
			// Add code to do the following:
			// 1) delete the first customer and store his info
			//    in timeArrived
			timeArrived = line.front();
			line.deleteQueue();
			// 2) increment totalServed
			totalServed++;
			// 3) calculate the waitTime of the customer
			waitTime = minute - timeArrived;
			// 4) add the waitTime of the customer to totalWait
			totalWait += waitTime;
			// 5) update maxWait if this customer waited longer than any
			// 	 previous customer.
			if(waitTime > maxWait){
				maxWait = waitTime;
			}

		}

		
        int k = rand() % 4 ;
        // The number generated above will be between 0 and 3
        // If 0 or 3, then no customers will be added, If 2, then 2
        // customers will be added. If 1, then one customer will be added.
        switch (k)
		{
		case 0 :
		case 3 : numArrivals = 0; break;
		case 1 : numArrivals = 1; break;
		case 2 : numArrivals = 2;
		}
		for ( int j = 0 ; j < numArrivals ; j++ )
			line.addQueue(minute);
	}

	cout << endl;
	cout << "Customers served : " << totalServed << endl;
	cout << "Average wait     : " << setprecision(2)
		<< (totalServed>0?(double(totalWait)/totalServed):0) << endl;
	cout << "Longest wait     : " << maxWait << endl;

	return 0;
}
