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

struct Queue ReadyQ;

void start_thread(void (*function)(void)) { 
	int stackSize = 8192;
	void *stackP = malloc(stackSize); //allocate stack
	struct TCB_t *tcb =(struct TCB_t*) malloc(sizeof(struct TCB_t)); //allocate a TCB
	init_TCB(tcb, function, stackP, stackSize); //initialize TCB
	addQueue(&ReadyQ, tcb); //add this TCB into ReadyQ which is a global head pointer
	 
}


void run() { 
	// real code
	ucontext_t parent; 		// get a place to store the main context, for faking
	getcontext(&parent); 	// magic sauce
	swapcontext(&parent, &(ReadyQ.head->context)); // start the first thread 
}


void yield() {
//	ucontext_t previous; //place to store main context
//	getcontext(&previous); 
	ucontext_t *previous = &(ReadyQ.head->context);
	rotateQueue(&ReadyQ); //rotate queue

	if(swapcontext(previous, &(ReadyQ.head->context))<0) //swap context from previous thread to current thread
	{
		printf("error in swapcontext");
		fflush(stdout);
	}
}
