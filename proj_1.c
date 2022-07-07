/*

 */
//#include "q.h" // already included in proj-2.c

/**		This program should be compiled using "gcc proj_1.c"		**/

/*
					SUPPORT FUNCTIONS
*/

/* printElement
 *     Descrip:
 *         prints the address of TCB_t element assumes that the 
 *         pointer passed is a pointer to some TCB_t object */
void printElement(struct TCB_t *element) {
	if (DEBUG && (element != NULL)) {
		printf("+-----------+-------------+\n");
		printf("|     adr:  | %p\n", element);
		printf("+-------------------------+\n");
		printf("| context:  | %p\n", &element->context);
		printf("|    prev:  | %p\n", element->prev);
		printf("|    next:  | %p\n", element->next);
		printf("+-----------+-------------+\n");
	} else if (element == NULL) {
		printf(" ~ Trying to print an element that is set to NULL.\n ~ Nothing to print.\n\n");
	}
}

/* printQueue
 *     Descrip:
 *         prints the address of the queue that was passed in,
 *         prints the addresses of each element within the queue,
 *         prints next & prev addresses of each TCB_t element */
void printQueue(struct Queue *queue) {
	int count1 = 1;
	struct TCB_t *temp = queue->head;

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
/*
int main() {
	struct Queue queue;	// allocate memory for queue
	initQueue(&queue); 	//create an empty queue

	struct TCB_t *item = newItem();
	struct TCB_t *element1 = newItem(); //created a qElement
	struct TCB_t *element2 = newItem(); //created a qElement
	struct TCB_t *element3 = newItem(); //created a qElement
	struct TCB_t *element4 = newItem(); //created a qElement
	
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

	printf("\n>>  !  <<\n    ROTATING QUEUE :\n>>  !  <<\n");
	rotateQueue(&queue);
	printQueue(&queue);

	freeItem(element1);
	freeItem(element2);
	freeItem(element3);
	freeItem(element4);
	return 0;
}
*/

