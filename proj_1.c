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
	if (DEBUG && (element != NULL)) {
		printf("+-----------+-------------+\n");
		printf("|     adr:  | %p\n", element);
		printf("+-------------------------+\n");
		printf("| payload:  | %d\n", element->payload);
		printf("|    prev:  | %p\n", element->prev);
		printf("|    next:  | %p\n", element->next);
		printf("+-----------+-------------+\n");
	} else if (element == NULL) {
		printf(" ~ Trying to print an element that is set to NULL.\n ~ Nothing to print.\n\n");
	}
}

void printQueue(struct Queue *queue) {
	int count1 = 1;
	struct qElement *temp = queue->head;

	if (DEBUG) {
		printf("\n\n");
		printf("*<<<<<<<<<<<<>>>>>>>>>>>>>*\n");
		printf("|       PRINT QUEUE       |\n");
		printf("*~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
		printf("|   count:    %d\n", queue->count);
		printf("|    head:    %p\n", queue->head);
		printf("*<<<<<<<<<<<<>>>>>>>>>>>>>*\n");
				
		int i;
		for(i = 0; i<queue->count; i++)
		{
			printf("+-----------+-------------+\n");
			printf("|  %d:         %p\n", i, temp);
			printElement(temp); 
			temp = temp->next;
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

	struct qElement *item = newItem();
	struct qElement *element1 = newItem(); //created a qElement
	struct qElement *element2 = newItem(); //created a qElement
	struct qElement *element3 = newItem(); //created a qElement
	struct qElement *element4 = newItem(); //created a qElement
	
	// Test our queue
	printQueue(&queue);

	printf("\n>>  !  <<\n    ADDING ELEMENT :\n>>  !  <<\n");
	printElement(element1);
	addQueue(&queue, element1);
	printQueue(&queue);

	printf("\n>>  !  <<\n    ADDING ELEMENT :\n>>  !  <<\n");
	printElement(element2);
	addQueue(&queue, element2);
	printQueue(&queue);

	printf("\n>>  !  <<\n    ADDING ELEMENT :\n>>  !  <<\n");
	printElement(element3);
	addQueue(&queue, element3);
	printQueue(&queue);

	printf("\n>>  !  <<\n    ADDING ELEMENT :\n>>  !  <<\n");
	printElement(element4);
	addQueue(&queue, element4);
	printQueue(&queue);

/*
	printf("\n>>  XX  <<\n    DELETING ELEMENT :\n>>  XX  <<\n");
	printElement(element1);
	item = delQueue(&queue);
	printQueue(&queue);
	printf("\n>>  -x-  <<\n    DELETED :\n>>  -x-  <<\n");
	printElement(item);

	printf("\n>>  XX  <<\n    DELETING ELEMENT :\n>>  XX  <<\n");
	printElement(element2);
	item = delQueue(&queue);
	printQueue(&queue);
	printf("\n>>  -x-  <<\n    DELETED :\n>>  -x-  <<\n");
	printElement(item);

	printf("\n>>  XX  <<\n    DELETING ELEMENT :\n>>  XX  <<\n");
	printElement(element3);
	item = delQueue(&queue);
	printQueue(&queue);
	printf("\n>>  -x-  <<\n    DELETED :\n>>  -x-  <<\n");
	printElement(item);

	printf("\n>>  XX  <<\n    DELETING ELEMENT :\n>>  XX  <<\n");
	printElement(element4);
	item = delQueue(&queue);
	printQueue(&queue);
	printf("\n>>  -x-  <<\n    DELETED :\n>>  -x-  <<\n");
	printElement(item);
*/
	printf("\n>>  !  <<\n    ROTATING QUEUE :\n>>  !  <<\n");
	rotateQueue(&queue);
	printQueue(&queue);

	freeItem(element1);
	freeItem(element2);
	freeItem(element3);
	freeItem(element4);
	return 0;
}

