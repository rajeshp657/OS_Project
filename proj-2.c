/*
 +--------------------------------------------------+
 | Filename: proj-2.c                               |
 +--------------------------------------------------+
 |           CSE 430, Programming Project 1         |
 |               Dasgupta T, Th 4:30 pm             |
 |                   March 27, 2014                 |
 |                                                  |
 |          Group: Doug Sheridan, 1202789648        |
 |                 Amy Mazzola,                     |
 +--------------------------------------------------+
 | Description: TODO                                |
 +--------------------------------------------------+
 */
#include "threads.h"
#include "proj_1.c" // for print methods & testing

/* Declare a global ReadyQ */
struct Queue ReadyQ;

/* Write a few functions with infinite loops (put a yield in each loop). 
   ! Note: try to write thread functions that aremeaningful, 
     use global and local variables ! */

void func_1() {
	while(1) {
		yield();
		printf("func_1");
	}
}

void func_2() {
	while(1) {
		yield();
		printf("func_2");
	}
}

void func_3() {
	while(1) {
		yield();
		printf("func_3");
	}
}


/*
						MAIN
*/
int main() {
	// initialize ReadyQ
	printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
	initQueue(&ReadyQ);
	printQueue(&ReadyQ);

	// start threads using the functions you defined using start_thread()
	printf("\n>>  S1  <<\n    STARTING THREAD 1 :\n>>  S1  <<\n");
	start_thread(func_1);

	printf("\n>>  S2  <<\n    STARTING THREAD 2 :\n>>  S2  <<\n");
	start_thread(func_2);

	printf("\n>>  S3  <<\n    STARTING THREAD 3 :\n>>  S3  <<\n");
	start_thread(func_3);

	// Call run() and watch
	run();
}
