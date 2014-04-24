/*
 +--------------------------------------------------+
 | Filename: sem.h                                  |
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
 #include "threads.h"

 extern struct Queue ReadyQ;

 // Semaphore data structure (A value field and a queue of TCBs.)
 struct sem {
 	int value;
 	struct Queue queue;
 };


// Initializes the value field with the specified value
void InitSem(struct sem* S, int value) {
	S->value = value;
	initQueue(&(S->queue));
}


void block(){
	while(1);
}


// The P (wait) routine decrements the semaphore, 
// and if the value is less than zero then blocks the process 
// in the queue associated with the semaphore.
void P(struct sem* S) {
	S->value--;
	while(S->value < 0){
		ucontext_t *previous=&(ReadyQ.head->context); //get current context

		//add a process to S->queue
		addQueue(&(S->queue), delQueue(&ReadyQ));
		swapcontext(previous, &(ReadyQ.head->context));
	}
}


// The V routine increments the semaphore, 
// and if the value is 0 or negative, then takes a PCB
// out of the semaphore queue and puts it into the ready queue.
// Note: The V routine also "yields" to the next runnable process. 
// this is important.
void V(struct sem* S) {
	S->value++;
	if(S->value <= 0){
		// remove a process from S->queue;
		addQueue(&ReadyQ, delQueue(&(S->queue)));
	}
	yield();
}
