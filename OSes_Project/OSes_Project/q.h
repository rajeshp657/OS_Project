/*
 +--------------------------------------------------+
 |	Filename: q.h								    |
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


/* Queue
		Descrip:	A q-element is a structure, consisting of a prev and next pointer, 
					and a payload consisting of 1 integer. The header is a pointer to the first 
					element of the queue. The header is null if the q is empty. */
struct Queue{
	int payload;		// integer payload
	struct Queue *head;	// always points to first element of queue
	struct Queue *prev;	// pointer to previous element in queue
	struct Queue *next;	// pointer to next element in queue
};


/******************************************************************************/
/**		Note:																 **/
/**		All routines work on pointers. They do NOT copy q-elements.			 **/
/**		Also, they do not allocate/deallocate space [except NewItem()].		 **/
/**		You may choose to implement an optional FreeItem(item) routine.		 **/
/******************************************************************************/

/* NewItem
		Inputs:		NONE
		Returns:	pointer to a new q-element		
		Descrip:	creates a new q-element, but does not do anything with it */
void NewItem() {

}

/* InitQueue
		Inputs:		&head, address of head
		Returns:	VOID
		Descrip:	creates an empty queue, pointed to by the variable head	*/
void InitQueue(&head) {

}

/* AddQueue
		Inputs:		&head, address of head 
					item, a queue item
		Returns:	VOID
		Descrip:	adds a queue item, pointed to by item, to the queue pointed to by head */
void AddQueue(&head, item) {

}

/* DelQueue
		Inputs:		&head, address of head 
		Returns:	pointer to the deleted item
		Descrip:	deletes an item from head */
void DelQueue(&head) {

}

/* RotateQueue
		Inputs:		&head, address of head 
		Returns:	VOID
		Descrip:	moves the header pointer to the next element in the queue */
void RotateQueue(&head) {

}