/*
 +--------------------------------------------------+
 |	Filename: q.hpp								    |
 +--------------------------------------------------+
 |		     CSE 430, Programming Project 2	        |
 |			     Dasgupta T, Th 4:30 pm			    |
 |				     March 27, 2014				    |
 |												    |
 |		  Group:	Doug Sheridan, 1202789648	    |
 |					Amy Mazzola,				    |
 +--------------------------------------------------+
 | Description:								        |
 |		This program contains routines necessary	|
 |		to perform standard queuing functions.		|
 |		The functions work on multiple queues,		|
 |		and structure each queue as a doubly		|
 |		linked, circular list.						|
 +--------------------------------------------------+
 */
#include <stdio.h>
#include <stdlib.h>

/* q
		Descrip:	A q-element is a structure, consisting of a prev and next pointer, 
					and a payload consisting of 1 integer. The header is a pointer to the first 
					element of the queue. The header is null if the q is empty. */
struct q {
	int payload;	// integer payload
	struct q *head;	// always points to first element of queue
	struct q *prev;	// pointer to previous element in queue
	struct q *next;	// pointer to next element in queue

	// Main routines
	void init(struct q head);
	void print();
};

/*
								ROUTINE HEADERS
*/


/*
								MAIN ROUTINES
*/
/******************************************************************************/
/**		Note:																 **/
/**		All routines work on pointers. They do NOT copy q-elements.			 **/
/**		Also, they do not allocate/deallocate space [except NewItem()].		 **/
/**		You may choose to implement an optional FreeItem(item) routine.		 **/
/******************************************************************************/

/* new
		Inputs:		NONE
		Returns:	pointer to a new q-element		
		Descrip:	creates a new q-element, but does not do anything with it */
/*
void new() {

}
*/

/* init
		Inputs:		&head, address of head
		Returns:	VOID
		Descrip:	creates an empty queue, pointed to by the variable head	*/
void init(struct q *&head) {
	// Initialize payload to 0
	head->payload = 0;
	// Set head to NULL
	head->head = NULL;
	// Set prev to head
	head->prev = head->head;
	// Set next to head
	head->next = head->head;
}

/* add
		Inputs:		&head, address of head 
					item, a queue item
		Returns:	VOID
		Descrip:	adds a queue item, pointed to by item, to the queue pointed to by head */
/*
void add(&head, item) {

}
*/

/* delete
		Inputs:		&head, address of head 
		Returns:	pointer to the deleted item
		Descrip:	deletes an item from head */
/*
void delete(&head) {

}
/*

/* rotate
		Inputs:		&head, address of head 
		Returns:	VOID
		Descrip:	moves the header pointer to the next element in the queue */
/*
void rotate(&head) {

}
/*

/*
								SUPPORT FUNCTIONS
*/

// prints the payload value of each queue element
// assumes that the pointer passed is a pointer to the head of the queue
void q::print() {
	//if (head->head
	printf("%d", payload);
}