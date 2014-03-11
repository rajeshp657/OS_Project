/*
 +--------------------------------------------------+
 |	Filename: q.h                                   |
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
	struct q* head; //points to first element in queue
};
	

	/* init
		Inputs:		&head, address of head
		Returns:	VOID
		Descrip:	creates an empty queue, pointed to by the variable head	*/
	void initQueue(struct Queue *queue) {
	/*	if (DEBUG) {
			cout << "+--------------+" << endl;
			cout << "+- BEFORE init +----------+" << endl;
			cout << "|   src adr :  | " << &queue << " |" << endl;
			cout << "+-------------------------+" << endl;
		}*/

		queue->head=NULL;	// points to first element of queue
/*
		if (DEBUG) {
			cout << "+--------------+" << endl;
			cout << "+- AFTER init  +----------+" << endl;
			cout << "|   src adr :  | " << &queue << " |"  << endl;
			cout << "+--------------+----------+" << endl;
		}*/
	}

	/* new
		Inputs:		NONE
		Returns:	pointer to a new q-element		
		Descrip:	creates a new q-element, but does not do anything with it */
	
	struct qElement* newItem()
	{
		struct qElement *element = (struct qElement*)malloc(sizeof(struct qElement));
		return element;

	}

	void freeItem(struct qElement *element)
	{
		free(element);
	}


	/* add
			Inputs:		&head, address of head 
						item, a queue item
			Returns:	VOID
			Descrip:	adds a queue item, pointed to by item, to the queue pointed to by head */
	/*
	void q::add(&head, item) {

	}
	*/

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

