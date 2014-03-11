/*
 +--------------------------------------------------+
 | Filename: proj_1.c                               |
 +--------------------------------------------------+
 |           CSE 430, Programming Project 2         |
 |               Dasgupta T, Th 4:30 pm             |
 |                   March 27, 2014                 |
 |                                                  |
 |          Group: Doug Sheridan, 1202789648        |
 |                 Amy Mazzola,                     |
 +--------------------------------------------------+
 | Description:                                     |
 |    This program is used to implement test        |
 |    case scenarios in order to prove that         |
 |    all requirements on q.hpp are met.            |
 +--------------------------------------------------+
 */
#include "q.h"

/**		This program should be compiled using "gcc proj_1.c"		**/

/*
					SUPPORT FUNCTIONS
*/

// prints the payload value of each queue element
// assumes that the pointer passed is a pointer to the head of the queue
void print_element(struct qElement *element) {
	if (DEBUG) {

		printf("+----------+----+\n");
		printf("| payload: | %d |\n", element->payload);
		printf("+----------+-------------+\n");
		printf("+   prev:  | %p\n", element->prev);
		printf("+   next:  | %p\n", element->next);
		printf("+----------+-------------+\n");
	}
}

int main() {

	struct Queue queue;	// allocate memory for queue
	printf("    queue: %p\n",&queue);
	printf("    head:  %p\n",&queue.head);

	initQueue(&queue); 	//create an empty queue

	struct qElement *element = newItem(); //created a qElement

	print_element(element);

	freeItem(element);

	return 0;
}

