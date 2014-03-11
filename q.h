/*
 +--------------------------------------------------+
 | Filename: q.h                                    |
 +--------------------------------------------------+
 |           CSE 430, Programming Project 2         |
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
/******************************************************************************/
/**	Note:                                                                    **/
/**	All routines work on pointers. They do NOT copy q-elements.              **/
/**	Also, they do not allocate/deallocate space [except NewItem()].          **/
/**	You may choose to implement an optional FreeItem(item) routine.          **/
/******************************************************************************/

#define DEBUG 1

/* q
		Descrip:	A q-element is a structure, consisting of a prev and next pointer, 
					and a payload consisting of 1 integer. The header is a pointer to the first 
					element of the queue. The header is null if the q is empty. */
struct qElement {

	int payload;	// integer payload
	struct qElement *prev;	// pointer to previous element in queue
	struct qElement *next;	// pointer to next element in queue
};

struct Queue{
	struct qElement* head; //points to first element in queue
};
	

/* initQueue
 *    Inputs:    &head, address of head
 *    Returns:   VOID
 *    Descrip:   creates an empty queue, pointed to by the variable head	*/
void initQueue(struct Queue *queue) {
	queue->head=NULL;	// initialize head to NULL
}


/* newItem
 *    Inputs:    NONE
 *    Returns:   pointer to a new q-element		
 *    Descrip:   creates a new q-element, but does not do anything with it */
struct qElement* newItem()
{
	struct qElement *element = (struct qElement*)malloc(sizeof(struct qElement));
	return element;
}

void freeItem(struct qElement *element)
{
	free(element);
}


/* addQueue
 *    Inputs:    &head, address of head to be added to 
 *               item, a queue element
 *    Returns:   VOID
 *    Descrip:   adds a queue item, pointed to by item, to the queue pointed to by head */
void addQueue(struct Queue *queue, struct qElement *item) {
	// Construct temp pointer as iterator
	struct qElement *temp;

	// Case where queue is empty, queue->head is NULL
	if (queue->head == NULL) {
		// Insert item as first element
		queue->head = item;
		item->prev = item;		// prev should point at itself
		item->next = NULL;		// point to NULL just as placeholder for printing, should actually point to itself
	} else {					// Case where the queue is not empty
		temp = queue->head;		// temp should start at the head
		// Loop through queue until we have pointer to last element
		while(temp->next != NULL) {
			// Move temp pointer to next element
			temp = temp->next;
		}   					// When loop ends, temp->next points to the end of the list
		
		// Add item to end of the queue
		temp->next = item;		// temp->next should point to item
		item->prev = temp;		// item->prev should point to temp
		item->next = NULL;//queue->head;	// item->next should point to head of queue, because it is the last element
		// Link the first element to the last element
		queue->head->prev = item;
	}
}


/* delete
		Inputs:		&head, address of head 
		Returns:	pointer to the deleted item
		Descrip:	deletes an item from head */
/*
void q::delete(&head) {

}
/*

/* rotate
		Inputs:		&head, address of head 
		Returns:	VOID
		Descrip:	moves the header pointer to the next element in the queue */
/*
void q::rotate(&head) {

}
*/

