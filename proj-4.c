/*
 +--------------------------------------------------+
 | Filename: proj-4.c                               |
 +--------------------------------------------------+
 |           CSE 430, Programming Project 2         |
 |               Dasgupta T, Th 4:30 pm             |
 |                   March 27, 2014                 |
 |                                                  |
 |          Group: Doug Sheridan, 1202789648        |
 |                 Amy Mazzola,                     |
 +--------------------------------------------------+
 | Description: TODO                                |
 +--------------------------------------------------+
 */
#include "sem.h"

#define BUFFER_SIZE 5

struct sem p;	// publish semaphore
struct sem s;	// subscribe semaphore

typedef struct {
	int value;
}item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int counter = 0;

void print_buffer(){
	int i;
	printf("\nBUFFER [ ");
	fflush(stdout);

	for(i=0;i<counter;i++){
		printf("%d ", buffer[i].value);
		fflush(stdout);
	}

	printf("]\n");
	fflush(stdout);
}

/*
	publish:
*/
void publish(){
	while(1){
		printf("\nPRODUCE");
		fflush(stdout);
		sleep(1);

		// produce an item in next_produced
		item next_produced;

		while(counter == BUFFER_SIZE){
			P(&p);
		}

		counter++;
		buffer[in] = next_produced;
		in = (in + 1) % BUFFER_SIZE;
		
		print_buffer();

		V(&c);
	}
}

/*
	subscribe:
*/
void subscribe(){
	while(1) {
		printf("\nCONSUME");
		fflush(stdout);
		sleep(1);

		item next_consumed;

		while(counter == 0) {
			P(&c);
		}

		counter--;
		next_consumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		print_buffer();
		
		V(&p);
	}
}

/* 	An idle process to handle the case where
	the RunQ is empty */
void idle(){
	while(1)
	{
		yield();
	}
}

/* Restrictions:
	
	1. Only 1 publisher
	
	2. # of subscribers is NOT known in advance, new subscribers may get created while the
		program is running. The number of subscribers is hence, dynamic.
	
	3. The total number of subscribers will not exceed 5. This keeps the code simple and arrays 			can be used to track the subscribers

	4. If a new subscriber joins, the first item it reads is any one of the items in the queue 			of unread items (recent past), or even the first item published in the future 
		(your choice).

	5. Subscribers do not terminate.

*/

/* Queue Restrictions:

	1. Do not use 5 queues or multiple queues

	2. There should only be 1 queue implemented using a circular array

	3. Items can be integers.

	4. All items published are to be read by all the subscribers

	5. Items sit in the slot in the buffer until all subscribers have read it

*/



/* Main program:

	1. Main program starts a publisher and then starts a subscriber

	2. After a few items the publisher starts another subscriber

	3. This continues until 5 subscribers have been created and no further ones are created

*/
int main() {
	printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n>>>>>>>>>>>>>>>>>> TEST BEGIN <<<<<<<<<<<<<<<<\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");

	// Initialize the semaphores
	InitSem(&p, 1);
	InitSem(&c, 1);

	// initialize ReadyQ
	printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
	initQueue(&ReadyQ);

	// start the idle thread
	printf("\n>>  IDLE  <<\n    STARTING IDLE PROCESS ...\n>>  IDLE  <<\n");
	start_thread(idle);

	// start the publisher
	printf("\n>>  P  <<\n    STARTING PUBLISHER ...\n>>  P  <<\n");
	start_thread(publish);

	// start the subscriber
	printf("\n>>  S  <<\n    STARTING SUBSCRIBER. ...\n>>  S  <<\n");
	start_thread(publish);
	
return 0;
}
