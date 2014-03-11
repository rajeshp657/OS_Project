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
void printElement(struct qElement *element) {
	if (DEBUG) {
		printf("+-----------+-------------+\n");
		printf("|     adr:  | %p\n", &*element);
		printf("+-------------------------+\n");
		printf("| payload:  | %d\n", element->payload);
		printf("|    prev:  | %p\n", element->prev);
		printf("|    next:  | %p\n", element->next);
		printf("+-----------+-------------+\n");
	}
}

void printQueue(struct Queue *queue) {
	struct qElement *temp = queue->head;
	int count = 1;

	if (DEBUG && (queue->head != NULL)) {
		printf("\n\n");
		printf("*<<<<<<<<<<<<>>>>>>>>>>>>>*\n");
		printf("|       PRINT QUEUE       |\n");
		printf("*<<<<<<<<<<<<>>>>>>>>>>>>>*\n");
		printf("|  %d :        %p\n", 0, &*temp);
		printElement(temp);
		
		while(temp->next != NULL) {
		temp = temp->next;
		printf("|  %d :        %p\n", count, &*temp);
		printElement(temp); count++;
		}
		printf("*>>>>>>>>>>>>><<<<<<<<<<<<*\n");
		printf("|   END OF PRINT QUEUE    |\n");
		printf("*>>>>>>>>>>>>><<<<<<<<<<<<*\n");
		printf("\n");

	}
}

/*
						MAIN
*/
int main() {

	struct Queue queue;	// allocate memory for queue
	initQueue(&queue); 	//create an empty queue

	struct qElement *element1 = newItem(); //created a qElement
	struct qElement *element2 = newItem(); //created a qElement
	struct qElement *element3 = newItem(); //created a qElement

	printf("\n>>  !  <<\nADDING ELEMENT :\n>>  !  <<\n");
	printElement(element1);
	addQueue(&queue, element1);
	printQueue(&queue);

	printf("\n>>  !  <<\nADDING ELEMENT :\n>>  !  <<\n");
	printElement(element2);
	addQueue(&queue, element2);
	printQueue(&queue);

	printf("\n>>  !  <<\nADDING ELEMENT :\n>>  !  <<\n");
	printElement(element3);
	addQueue(&queue, element3);
	printQueue(&queue);

	freeItem(element1);
	freeItem(element2);
	freeItem(element3);

	return 0;
}

