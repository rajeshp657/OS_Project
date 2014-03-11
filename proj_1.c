/*
 +--------------------------------------------------+
 |	Filename: proj_1.cpp						    |
 +--------------------------------------------------+
 |		    CSE 430, Programming Project 2	        |
 |			    Dasgupta T, Th 4:30 pm			    |
 |				    March 27, 2014				    |
 |												    |
 |		  Group:	Doug Sheridan, 1202789648	    |
 |					Amy Mazzola,				    |
 +--------------------------------------------------+
 | Description:								        |
 |		This program is used to implement test		|
 |		case scenarios in order to prove that		|
 |		all requirements on q.hpp are met.			|
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

		printf("%s\n","+----------+----+");
		printf("%s%d\n","| payload: | ",element->payload);
		printf("%s\n","+----------+---------+");
		printf("%s%p\n","+   prev:  | ",element->prev);
		printf("%s%p\n","+   next:  | ",element->next);
		printf("%s\n","+----------+---------+");
	}
}

int main() {

	struct Queue queue;	// allocate memory for queue
	

	initQueue(&queue); 		//create an empty queue

	struct qElement *element = newItem(); //created a qElement

	print_element(element);

	freeItem(element);

	return 0;
}

