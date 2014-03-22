/*
 +--------------------------------------------------+
 | Filename: threads.h                              |
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
#include "q.h"


void start_thread(void (*function)(void)) { 
	/* begin pseudo code 
			1. allocate a stack (via malloc) of a certain size (choose 8192) 
			2. allocate a TCB (via malloc) 
			3. call init_TCB with appropriate arguments
			4. call addQ to add this TCB into the “ReadyQ” which is a global head pointer 
	   end pseudo code */

}


void run() { 
	// real code
	ucontext_t parent; 		// get a place to store the main context, for faking
	getcontext(&parent); 	// magic sauce
	swapcontext(&parent, &(ReadyQ.head->context)); // start the first thread 
}


void yield() { // similar to run 
	/*  rotate the ready Q; 
		swap the context, from previous thread to the thread pointed to by readyQ */

}