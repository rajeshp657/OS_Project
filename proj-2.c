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

int x=0;

/* Write a few functions with infinite loops (put a yield in each loop). 
   ! Note: try to write thread functions that aremeaningful, 
     use global and local variables ! */

void func_1() {
	int a, loop;			// a will represent 2^n
	a=1;
	while(1) {
		printf("\n==================== LOOP %d ====================\n", x);
		printf("\n    Thread[%d]", x%3);		// if unwanted context switching occurs, thread index will be off
		printf("\n            2^%d :%d", loop, a);
		printf("\n   Internal loop #%d\n", loop);
		a = a*2;
		loop++;
		x++;
		sleep(2);
		yield();
	}
}

void func_2() {
	int b, loop;			// b will represent all positive even numbers
	b=0;
	while(1) {
		printf("\n==================== LOOP %d ====================\n", x);
		printf("\n\t\t    Thread[%d]", x%3);		// if unwanted context switching occurs, thread index will be off
		printf("\n\t\tPositive evens:%d", b);
		printf("\n\t\tInternal loop #%d\n", loop);
		b = b+2;
		loop++;
		x++;
		sleep(2);
		yield();
	}
}

void func_3() {
	int c, loop;			// c will represent all positive odd numbers
	c=1;
	while(1) {
		printf("\n==================== LOOP %d ====================\n", x);
		printf("\n\t\t\t\t    Thread[%d]", x%3);		// if unwanted context switching occurs, thread index will be off
		printf("\n\t\t\t\tPositive odds :%d", c);
		printf("\n\t\t\t\tInternal loop #%d\n", loop);
		c = c+2;
		loop++;
		x++;
		sleep(2);
		yield();
	}
}


/*
						MAIN
*/
int main() {
	// initialize ReadyQ
	printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
	initQueue(&ReadyQ);

	// start threads using the functions you defined using start_thread()
	printf("\n>>  S1  <<\n    STARTING THREAD 1. ...\n>>  S1  <<\n");
	start_thread(func_1);
	

	printf("\n>>  S2  <<\n    STARTING THREAD 2.. ...\n>>  S2  <<\n");
	start_thread(func_2);


	printf("\n>>  S3  <<\n    STARTING THREAD 3... ...\n>>  S3  <<\n");
	start_thread(func_3);
	
	printf("\n>>  R  <<\n    RUN...\n>>  R  <<\n");
	run();
}
