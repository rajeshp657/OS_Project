/*
 +--------------------------------------------------+
 | Filename: proj-3.c                               |
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

// Use this to switch between testing method 1 and method 2
// Set value to 1 if testing, 0 if not testing
#define M1 1
#define M2 0

#define BUFFER_SIZE 10

int x=0;

struct sem S;
struct sem p;
struct sem c;

// Method 1 (m1):
// Each thread is an infinite loop, and has a critical section
// using a mutex semaphore. The thread gets into the CS, prints
// values of global and local variables (like proj1), sleeps and
// exists the CS. Then it prints a message and sleeps and then repeats.

// An idle process to handle the case where
// the RunQ is empty
void idle(){
	while(1)
	{
		yield();
	}
}


void m1_f1(){
	int y=0;

	printf("\n\t\tFUNC 1 START...");
	fflush(stdout);

	P(&S);

	while(1){
		printf("\n\t\tFUNC 1");
		fflush(stdout);

		// wait for semaphore
		P(&S);

		// enter critical section	
		x++;
		y++;

		// print values of global and local variables
		printf("\n\t\tx: %d", x);	
		fflush(stdout);
		printf("\n\t\ty: %d", y);
		fflush(stdout);

		// sleep
		V(&S);
		sleep(1);	// this is to slow down printing

		// print a message
		printf("\n\t\tf1 woke up!");
		fflush(stdout);

	}
}

void m1_f2(){
	int y=0;
	
	printf("\n\t\t\t\tFUNC 2 START...");
	fflush(stdout);
	
	V(&S);

	while(1){
		printf("\n\t\t\t\tFUNC 2");
		fflush(stdout);

		// wait for semaphore
		P(&S);

		// enter critical section	
		x++;
		y++;

		// print values of global and local variables
		printf("\n\t\t\t\tx: %d", x);	
		fflush(stdout);
		printf("\n\t\t\t\ty: %d", y);
		fflush(stdout);

		// sleep
		V(&S);
		sleep(1);	// this is to slow down printing

		// print a message
		printf("\n\t\t\t\tf2 woke up!");
		fflush(stdout);

	}
}


void m1_f3(){
V(&S);
	int y=0;
	
	printf("\n\t\t\t\t\t\tFUNC 3 START...");
	fflush(stdout);

	while(1){
		printf("\n\t\t\t\t\t\tFUNC 3");
		fflush(stdout);

		// wait for semaphore
		P(&S);

		// enter critical section	
		x++;
		y++;

		// print values of global and local variables
		printf("\n\t\t\t\t\t\tx: %d", x);	
		printf("\n\t\t\t\t\t\ty: %d", y);

		// sleep
		V(&S);
		sleep(1);	// this is to slow down printing

		// print a message
		printf("\n\t\t\t\t\t\tf3 woke up!");

	}
}


// Method 2:
// Write a producer consumer solution, using the code
// given in class (see notes). Run 2 producers and 2 consumers.
// You will have to work out some details.
// If you choose to do this you really should do method 1 first.
// Also, doing this will make it easier for you to do project 4.
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
	PRODUCER:

		PRODUCE() {
			if (count == n) {
				p.wait		// wait on CONDITION p
			}
			count++
			add to buffer
			c.signal		// same as signal(c)
		}
*/
void produce(){
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
	CONSUMER:

		CONSUME() {
			if (count == 0) {
				c.wait		// wait on CONDITION c
			}
			count--
			take from buffer		// something like item = buffer[out]
			p.signal
		}
*/
void consume(){
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


int main(){
	// METHOD 1
	if (M1 & !M2) {
		printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("\n>>>>>>>>>>>>>>>>>>> METHOD 1 <<<<<<<<<<<<<<<<<\n");
		printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");

		// Initialize the semaphore
		InitSem(&S, 1);

		// initialize ReadyQ
		printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
		initQueue(&ReadyQ);
		
		printf("\n>>  IDLE  <<\n    STARTING IDLE PROCESS ...\n>>  IDLE  <<\n");
		start_thread(idle);

		printf("\n>>  F1  <<\n    STARTING FUNC 1. ...\n>>  F1  <<\n");
		start_thread(m1_f1);

		printf("\n>>  F2  <<\n    STARTING FUNC 2.. ...\n>>  F2  <<\n");
		start_thread(m1_f2);

		printf("\n>>  F3  <<\n    STARTING FUNC 3... ...\n>>  F3  <<\n");
		start_thread(m1_f3);

		printf("\n>>  R  <<\n    RUN...\n>>  R  <<\n");
		run();
	}
	// METHOD 2
	else if(M2 && !M1){
		printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("\n>>>>>>>>>>>>>>>>>>> METHOD 2 <<<<<<<<<<<<<<<<<\n");
		printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");

		// Initialize the semaphores
		InitSem(&p, 1);
		InitSem(&c, 1);

		// initialize ReadyQ
		printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
		initQueue(&ReadyQ);

		printf("\n>>  IDLE  <<\n    STARTING IDLE PROCESS ...\n>>  IDLE  <<\n");
		start_thread(idle);

		printf("\n>>  P1  <<\n    STARTING PRODUCER 1. ...\n>>  P1  <<\n");
		start_thread(produce);

		printf("\n>>  P2  <<\n    STARTING PRODUCER 2.. ...\n>>  P2  <<\n");
		start_thread(produce);

		printf("\n>>  C1  <<\n    STARTING CONSUMER 1. ...\n>>  C1  <<\n");
		start_thread(consume);

		printf("\n>>  C2  <<\n    STARTING CONSUMER 2.. ...\n>>  C2  <<\n");
		start_thread(consume);

		printf("\n>>  R  <<\n    RUN...\n>>  R  <<\n");
		run();
	} else {
		printf("\nSET #DEFINE M1 OR M2 TO 1, TO SELECT THE TEST METHOD.\n");
	}

	return 0;
}
