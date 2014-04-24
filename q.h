/*
 +--------------------------------------------------+
 | Filename: q.h                                    |
 +--------------------------------------------------+
 |           CSE 430, Programming Project 1         |
 |               Dasgupta T, Th 4:30 pm             |
 |                   March 27, 2014                 |
 |                                                  |
 |          Group: Doug Sheridan, 1202789648        |
 |                 Amy Mazzola,                     |
 +--------------------------------------------------+
 | Description:                                     |
 |    This program contains routines necessary      |
 |    to perform standard queuing functions.        |
 |    The functions work on multiple queues,        |
 |    and structure each queue as a doubly          |
 |    linked, circular list.                        |
 +--------------------------------------------------+
 */
#include <stdio.h>
#include <stdlib.h>

#include "tcb.h"
 
/******************************************************************************/
/**	Note:                                                                    **/
/**	All routines work on pointers. They do NOT copy q-elements.              **/
/**	Also, they do not allocate/deallocate space [except NewItem()].          **/
/**	You may choose to implement an optional FreeItem(item) routine.          **/
/******************************************************************************/

#define DEBUG 1

/* qElement
		Descrip:	This is a dummy structure that immitates what a TCB_t
					is. Used for project 1 only. No longer used. */
struct qElement {

	int payload;	// integer payload
	struct qElement *prev;	// pointer to previous element in queue
	struct qElement *next;	// pointer to next element in queue
};

/* Queue
		Descrip:	A TCB_t is a structure, consisting of a prev and next pointer, 
					and a payload consisting of 1 integer. The head is a pointer to the first 
					element of the queue. The head is null if the queue is empty. */
struct Queue {
	struct TCB_t* head; //points to first element in queue
	int count;
};
	

/* initQueue
 *    Inputs:    &head, address of head
 *    Returns:   VOID
 *    Descrip:   creates an empty queue, pointed to by the variable head	*/
void initQueue(struct Queue *queue) {
	queue->head=NULL;	// initialize head to NULL
	queue->count=0;
}


/* newItem
 *    Inputs:    NONE
 *    Returns:   pointer to a new q-element		
 *    Descrip:   creates a new q-element, but does not do anything with it */
struct TCB_t* newItem()
{
	struct TCB_t *element = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	return element;
}

/* freeItem
 *    Inputs:    NONE
 *    Returns:   NONE	
 *    Descrip:   used for removing an element from memory */
void freeItem(struct TCB_t *element)
{
	free(element);
}


/* addQueue
 *    Inputs:    &queue, address of head to be added to 
 *               item, a queue element
 *    Returns:   VOID
 *    Descrip:   adds a queue item, pointed to by item, to the queue pointed to by head */
void addQueue(struct Queue *queue, struct TCB_t *item) {
	// Case where queue is empty, queue->head is NULL
	if (queue->head == NULL) {
		// Insert item as first element
		queue->head = item;			// head points to first element					
		queue->head->prev = item;	// prev should point at itself
		queue->head->next = item;	// next points to itself 
		queue->count++;				// increase count of elements for printing
	} else {
		struct TCB_t *tail = queue->head->prev; 		// tail element
		item->next = queue->head;	// next points to head
		item->prev = tail;			// link first element to last element
		queue->head->prev = item; 	// set head tail to item
		tail->next = item;			// make old tail next point to item
		queue->count++;				// increase count of elements for printing
	}
}


/* DelQueue
 *		Inputs:		&head, address of head 
 *		Returns:	pointer to the deleted item
 *		Descrip:	deletes an item from head, assumes FIFO structure */
struct TCB_t* delQueue(struct Queue *queue) {
	struct TCB_t *temp;
	
	// Check if queue is empty
	if (queue->head != NULL) {
		temp  = queue->head; // save a pointer to the first element

		// Remove the first element, because we can assume FIFO
		if ((queue->head != queue->head->prev) && (queue->head != queue->head->next)) {		 // if there are more than one elements
			queue->head->next->prev = queue->head->prev; // Set 2nd element's prev to the last element
			queue->head->prev->next = queue->head->next; // Set last element's next to 2nd element
			queue->count--;					 // decrement count, because we just removed an element
			queue->head = queue->head->next; // Set the queue head to the 2nd element
		} else {	// case where there is one element
			queue->head = NULL;	// head should point to NULL, because there are no more elements in the queue
			queue->count--;		// this should always set count to 0, if not, there is an error somewhere
		}

		// Set the deleted element's pointers to NULL
		temp->next = NULL;
		temp->prev = NULL;

	} else {	// Queue is empty
		return NULL;
	}

	// Return the deleted itema
	return temp;
}


/* RotateQueue
		Inputs:		&head, address of head 
		Returns:	VOID
		Descrip:	moves the header pointer to the next element in the queue */
void rotateQueue(struct Queue *queue) {
	addQueue(queue, delQueue(queue));
}


