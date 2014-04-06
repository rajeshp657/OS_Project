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

int x=0;

struct sem S;

// Method 1 (m1):
// Each thread is an infinite loop, and has a critical section
// using a mutex semaphore. The thread gets into the CS, prints
// values of global and local variables (like proj1), sleeps and
// exists the CS. Then it prints a message and sleeps and then repeats.

void m1_f1(){
	int y=0;
	printf("\n\t\tFUNC 1 START...");
	while(1){
		printf("\n\t\tFUNC 1");

		// wait for semaphore
		P(&S);

		// enter critical section	
		x++;
		y++;

		// print values of global and local variables
		printf("\n\t\tx: %d", x);	
		printf("\n\t\ty: %d", y);

		// sleep
		V(&S);
		sleep(1);	// this is to slow down printing

		// print a message
		printf("\n\t\tf1 woke up!");

		// sleep
		V(&S);
	}
}

void m1_f2(){
	int y=0;
	printf("\n\t\t\t\tFUNC 2 START...");

	while(1){
		printf("\n\t\t\t\tFUNC 2");

		// wait for semaphore
		P(&S);

		// enter critical section	
		x++;
		y++;

		// print values of global and local variables
		printf("\n\t\t\t\tx: %d", x);	
		printf("\n\t\t\t\ty: %d", y);

		// sleep
		V(&S);
		sleep(1);	// this is to slow down printing

		// print a message
		printf("\n\t\t\t\tf2 woke up!");

		// sleep
		V(&S);
	}
}


void m1_f3(){
	int y=0;
	printf("\n\t\t\t\t\t\tFUNC 3 START...");

	while(1){
		printf("\n\t\t\t\t\t\tFUNC 3");

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

		// sleep
		V(&S);
	}
}


// Method 2:
// Write a producer consumer solution, using the code
// given in class (see notes). Run 2 producers and 2 consumers.
// You will have to work out some details.
// If you choose to do this you really should do method 1 first.
// Also, doing this will make it easier for you to do project 4.

// TODO
/*
void method_2(){

}
*/


int main(){
	// METHOD 1
	if (M1) {
		// Initialize the semaphore
		InitSem(&S, 1);

		// initialize ReadyQ
		printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
		initQueue(&ReadyQ);

		// start threads using the functions you defined using start_thread()
		printf("\n>>  F1  <<\n    STARTING FUNC 1. ...\n>>  F1  <<\n");
		start_thread(m1_f1);

		// start threads using the functions you defined using start_thread()
		printf("\n>>  F2  <<\n    STARTING FUNC 2.. ...\n>>  F2  <<\n");
		start_thread(m1_f2);

		// start threads using the functions you defined using start_thread()
		printf("\n>>  F3  <<\n    STARTING FUNC 3... ...\n>>  F3  <<\n");
		start_thread(m1_f3);

		printf("\n>>  R  <<\n    RUN...\n>>  R  <<\n");
		run();
	}

	// METHOD 2
	if(M2){
		
	}

	return 0;
}