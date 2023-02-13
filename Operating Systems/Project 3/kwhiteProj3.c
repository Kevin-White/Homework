#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <stdbool.h>

#define BUFFSIZE 5

/*
This struct holds our buffer and read/write variables 
to keep track of the number of times that is has been 
writen to or read from
*/
struct Buffer
{
	int hold[BUFFSIZE];
	int read;
	int write;
};

/*
This is a group of global vars for all the different
threads to use and keep track of stats better for the
end result print
*/

struct Buffer buff;

sem_t fullBuffer;
sem_t emptyBuffer;

int fullCount = 0;
int emptyCount = 0;

pthread_mutex_t mutex;

int threadWaitTime;
bool mainWait;
bool display;

/*
This proFun function produces random numbers to then
push to the buffer this uses a combonation of mutex locks
as well as semaphores to protect the critical section
*/
void *proFun(void *arg)
{
	while (mainWait)
	{
	    
		int x = rand() % 100;
		sleep(rand() % threadWaitTime);

		int value;
		sem_getvalue(&emptyBuffer, &value);
		if (!value)
		{
			if(display){
			    printf("All buffers full.  Producer %lu waits.\n\n", pthread_self());
			}
			fullCount++;
		}
		sem_wait(&emptyBuffer);
		pthread_mutex_lock(&mutex);
		*((int*)arg) = *((int*)arg) + 1;
		buff.hold[buff.write % 5] = x;
		buff.write = buff.write + 1;
		if (display)
		{
			printf("Producer %lu writes %d\n", pthread_self(), x);
			printf("(buffers occupied: %d)\n", buff.write - buff.read);
			printf("buffers:");
			int i;
			for (i = 0; i < BUFFSIZE; i++)
			{
				printf("   %d", buff.hold[i]);
			}
			printf("\n         ---- ---- ---- ---- ----\n         ");

			for (i = 0; i < BUFFSIZE; i++)
			{
				if ((i == buff.read % 5) && (i == buff.write % 5))
				{
					if (buff.read == buff.write)
					{
						printf(" WR  ");
					}
					else
					{
						printf(" RW  ");
					}
				}
				else if (i == buff.read % 5)
				{
					printf(" R   ");
				}
				else if (i == buff.write % 5)
				{
					printf(" W   ");
				}
				else
				{
					printf("     ");
				}
			}
			printf("\n\n");
		}
		pthread_mutex_unlock(&mutex);
		sem_post(&fullBuffer);
	}
}

/*
This conFun function consumes numbers from the buffer
this function uses a combonation of mutex locks as
well as semaphores to protect the critical section
this function can also find out wether the number
consumed is prime or not
*/
void *conFun(void *arg)
{
	while (mainWait)
	{
		int x;
		int i;
		bool isPrime = true;
		sleep(rand() % threadWaitTime);
		int value;
		sem_getvalue(&fullBuffer, &value);
		if (!value)
		{
			if(display){
			    printf("All buffers empty.  Consumer %lu waits.\n\n", pthread_self());
			}
			emptyCount++;
		}
		sem_wait(&fullBuffer);
		pthread_mutex_lock(&mutex);
		*((int*)arg) = *((int*)arg) + 1;
		x = buff.hold[buff.read % 5];
		buff.read = buff.read + 1;

		if(x == 0 || x == 1){
			isPrime = false;
		}else{
			for(i = 2; i < x / 2; ++i){
				if(x % i == 0){
					isPrime = false;
					break;
				}
			}
		}
		
		if (display)
		{
			printf("Consumer %lu reads %d", pthread_self(), x);
			if(isPrime){
				printf("   * * * PRIME * * *\n");
			}else{
				printf("\n");
			}
			printf("(buffers occupied: %d)\n", buff.write - buff.read);
			printf("buffers:");
			for (i = 0; i < BUFFSIZE; i++)
			{
				printf("   %d", buff.hold[i]);
			}
			printf("\n         ---- ---- ---- ---- ----\n         ");

			for (i = 0; i < BUFFSIZE; i++)
			{
				if ((i == buff.read % 5) && (i == buff.write % 5))
				{
					if (buff.read == buff.write)
					{
						printf(" WR  ");
					}
					else
					{
						printf(" RW  ");
					}
				}
				else if (i == buff.read % 5)
				{
					printf(" R   ");
				}
				else if (i == buff.write % 5)
				{
					printf(" W   ");
				}
				else
				{
					printf("     ");
				}
			}
			printf("\n\n");
		}
		pthread_mutex_unlock(&mutex);
		sem_post(&emptyBuffer);
	}
}

/*
This main function takes arguments from the user in
order to determen how long this program runs for
how long the waiting period is between thread runs
and the number of threads in this program.

Once this information has been gathered the function
will create threads in order to run for the given time
at the end of the program time, the main function sends
out a false to stop the loops in the proFun and conFun
it will then wait for all threads to finish up there processes 
before showing statistics gathered during the run time of
the program
*/
int main(int argc, char *argv[])
{
	srand(time(NULL));
	int mainWaitTime = atoi(argv[1]);
	threadWaitTime = atoi(argv[2]);
	int proNum = atoi(argv[3]);
	int conNum = atoi(argv[4]);

	if (argv[5][0] == 'y' || argv[5][0] == 'Y')
	{
		display = true;
	}
	else
	{
		display = false;
	}

	mainWait = true;
	buff.read = 0;
	buff.write = 0;
	int i;
	for (i = 0; i < BUFFSIZE; i++)
	{
		buff.hold[i] = -1;
	}

	pthread_t pro[proNum];
	int tpc[proNum];
	pthread_t con[conNum];
	int tcc[conNum];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&fullBuffer, 0, 0);
	sem_init(&emptyBuffer, 0, 5);

    if(display){
	    printf("Starting Threads...\n");
	    printf("(buffers occupied: 0)\n");
	    printf("buffers:  -1   -1   -1   -1   -1\n");
	    printf("         ---- ---- ---- ---- ----\n");
	    printf("          WR\n\n");
    }
	for (i = 0; (i < proNum) || (i < conNum); i++)
	{
		if (i < proNum)
		{
		    tpc[i] = 0;
			pthread_create(&pro[i], NULL, &proFun, &tpc[i]);
		}
		if (i < conNum)
		{
		    tcc[i] = 0;
			pthread_create(&con[i], NULL, &conFun, &tcc[i]);
		}
	}
	sleep(mainWaitTime);
	mainWait = false;
	sleep(threadWaitTime);
	printf("PRODUCER / CONSUMER SIMULATION COMPLETE\n");
	printf("=======================================\n");
	printf("Simulation Time:\t\t\t%d\n", mainWaitTime);
	printf("Maximum Thread Sleep Time:\t\t%d\n", threadWaitTime);
	printf("Number of Producer Threads:\t\t%d\n", proNum);
	printf("Number of Consumer Threads:\t\t%d\n", conNum);
	printf("Size of Buffer:\t\t\t\t%d\n", BUFFSIZE);
	

	printf("Total Number of Items Produced:\t\t\t%d\n", buff.write);
	for(i = 0; i < proNum; i++){
        printf("Thread %d: %d\n", i+1, tpc[i]);
	}

	printf("Total Number of Items Consumed:\t\t\t%d\n", buff.read);
    for(i = 0; i < conNum; i++){
        printf("Thread %d: %d\n", i+1, tcc[i]);
	}

	printf("Number Of Items Remaining in Buffer:\t%d\n", buff.write - buff.read);
	printf("Number Of Times Buffer Was Full:\t%d\n", fullCount);
	printf("Number Of Times Buffer Was Empty:\t%d\n", emptyCount);
}
