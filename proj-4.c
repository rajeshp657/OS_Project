/*
 +--------------------------------------------------+
 | Filename: proj-4.c                               |
 +--------------------------------------------------+
 |           CSE 430, Programming Project 2         |
 |               Dasgupta T, Th 4:30 pm             |
 |                   March 27, 2014                 |
 |                                                  |
 |          Group: Doug Sheridan, 1202789648        |
 |                 Amy Mazzola,                     |
 +--------------------------------------------------+
 | Description: TODO                                |
 +--------------------------------------------------+
 */
#include "sem.h"

#define BUFFER_SIZE 5

void subscribe();

struct sem p;	// publish semaphore
struct sem s;	// subscribe semaphore

typedef struct {
	int value;
	int subs[5]; // binary array to keep track of which subscribers have or haven't consumed this item yet
}item;

int sc = 0; // subscriber count, should never be greater than 5
int ic = 0; // item count

item* buffer[BUFFER_SIZE];
int in = 0;				// next index to be created
int out = 0;			// next index to be consumed
int counter = 0;		// number of items currently in the buffer
int loopCount = 0; 		// keep track of how many total items have been published

void init_item(item* i) {
	int x;
	i->value = 1;
	for(x=0; x<5; x++){
		i->subs[x] = 0;
	}
}

void print_item(item* i) {
	printf("\n#+++++++++++++++++++++#");
	// printf("\n~ value = %d", i->value);
	// printf("\n# subs  = ");
	printf("\n#  [");
	int x;
	for(x=0; x<5; x++){
		printf(" %d ", i->subs[x]);
	}
	printf("]  #");
	printf("\n#+++++++++++++++++++++#");
}

void print_buffer(){
	int i;
	printf("\n\n#######################");
	printf("\n#       BUFFER        #");
	printf("\n#---------------------#");
	printf("\n#  [");
	fflush(stdout);

	for(i=0; i<BUFFER_SIZE; i++){
		if(buffer[i] != NULL){
			printf(" %d ", buffer[i]->value);
			fflush(stdout);
		} else {
			printf(" 0 ");
		}
	}
	
	printf("]  #");
	printf("\n#     counter = %d     #", counter);
	printf("\n#---------------------#");

	for(i=0; i<BUFFER_SIZE; i++){
		if(buffer[i] != NULL){
			if(buffer[i]->value != 0){
				printf("\n#                     #");
				printf("\n# ITEM[ %d ]:          #", i);
				print_item(buffer[i]);
			}
		}
	}

	printf("\n#######################");
	fflush(stdout);
}

/*
	Loop through the item's subs[] array and mark all active subscribers
	need to read the item, only done on initialization of item
	We can assume that because the item was just created, none of the
	subscribers have read the item
*/
void mark_subs(item *i){
	int x;
	for(x=0; x<sc; x++){
		i->subs[x] = 1;
	}
}

/*
	Call this method every time a subscriber loops,
	to add itself to the list of subscribers that have yet to read an item
	This ensures that all items created before the subscriber was created
	are now aware that there exists a new subscriber that has yet to read it
*/
void update_items(int subId){
	int x;
	for(x=0; x<BUFFER_SIZE; x++){
		if (buffer[x] != NULL) {
			if(buffer[x]->value == 1){
				if (buffer[x]->subs[subId] == 0){
					buffer[x]->subs[subId] = 1;	// value of 1 means the subscriber with this subId has not read me yet
				}
			}
		}
	}
}

/*
	publish:
*/
void publish(){
	while(1){
		printf("\n___________________________________________");
		printf("\n\n\t\tPUBLISH");
		printf("\n___________________________________________");
		fflush(stdout);
		sleep(1);

		// produce an item in next_produced
		item *next_published = (item*) malloc(sizeof(item));
		init_item(next_published);
		ic++; // increment item count
		mark_subs(next_published);
		while(counter == BUFFER_SIZE){
			P(&p);
		}

		counter++;
		buffer[in] = next_published;
		in = (in + 1) % BUFFER_SIZE;
		
		print_buffer();

		V(&s);

	}
}

void delete_item(item *i){
	free(i);
}

/* 
	Method that checks whether or not the item can be removed.
	An item may only be removed once there exists no active
	subscribers that has yet to read the item.
*/
int remove_item(item *i){
	// If the number of 2's in the subs[] array is equal to the number
	// of subscribers, we can remove the item from the buffer
	int twoCount = 0;
	int x;

	for(x=0; x<5; x++){
		if(i->subs[x] == 2){
			twoCount++;
		}
	}
	
	if(twoCount == sc){
		printf("\n\t\tITEM REMOVED");
		delete_item(i);
		counter--;
		ic--; // decrement item count
		return 1;
	}
}

/*
	Called when a subscriber is about to read an item
	This method needs to check to make sure no one else is modifying
	the current item's values
*/
void read_item(int subId, int out){
	// Try to read the next item in the buffer
	printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	printf("\n\t\tREADING ITEM");

	item *next_consumed;
	int next = (out-1)%5;
	int index;

	// Remove itself from the list of subscribers that have yet to read the item
	// by flipping its index value from 1 to 2
	if(buffer[out] == NULL){
		// We just tried to read an empty buffer slot,
		// so, try reading the next item
		index = next;  
		if(buffer[index] == NULL)
		{
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			return;
		}	
	} else {
		index = out; 
	}

	// if there is an item here,
	// mark it with a 2, 
	// which means 'we have read the item!'
	if(buffer[index]->value == 1) {
		buffer[index]->subs[subId] = 2;
	}

	// call remove_item to check if we are allowed to delete the item from the buffer
	int removed = remove_item(buffer[index]);
	if(removed == 1) {
		buffer[index] = NULL;
	}
	printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}

/*
	subscribe:
*/
void subscribe(){
	int subscriberID = sc;	// give each subscriber an ID
	sc++;					// incremement subscriber count
	int nextRead = out; 	// integer that keeps track of which item index was just read

	while(1) {
		printf("\n___________________________________________");
		printf("\n\n\t\tSUBSCRIBER[ %d ]", subscriberID);
		printf("\n\t\tloopCount = %d", loopCount);
		printf("\n\t\tsc = %d", sc);
		printf("\n___________________________________________");
		fflush(stdout);
		sleep(1);

		// Update all items in buffer,
		// let them know that this thread hasn't read them yet
		update_items(subscriberID);

		while(counter == 0) {
			P(&s);
		}

		// Consume an item, "read the item"
		read_item(subscriberID, nextRead);
		nextRead = (nextRead+1)%5;
		out = (out + 1) % BUFFER_SIZE;
	
		print_buffer();
		
		V(&p);
		
		loopCount++;
		// After a few items (2) the subscriber starts another subscriber
		if (loopCount == 2 || loopCount == 3 || loopCount == 4 || loopCount == 5) {
			start_thread(subscribe);
		}
	}
}

/* 	An idle process to handle the case where
	the RunQ is empty */
void idle(){
	while(1)
	{
		yield();
	}
}

/* Main program:

	1. Main program starts a publisher and then starts a subscriber
	2. After a few items the publisher starts another subscriber
	3. This continues until 5 subscribers have been created and no 
			further ones are created
*/
int main() {
	printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n>>>>>>>>>>>>>>>>>> TEST BEGIN <<<<<<<<<<<<<<<<\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");

	// Initialize the semaphores
	InitSem(&p, 1);
	InitSem(&s, 1);

	// initialize ReadyQ
	printf("\n>>  I  <<\n    INITIALIZING READY QUEUE :\n>>  I  <<\n");
	initQueue(&ReadyQ);

	// start the idle thread
	printf("\n>>  IDLE  <<\n    STARTING IDLE PROCESS ...\n>>  IDLE  <<\n");
	start_thread(idle);

	// start the publisher
	printf("\n>>  P  <<\n    STARTING PUBLISHER ...\n>>  P  <<\n");
	start_thread(publish);

	// start the subscriber
	printf("\n>>  S  <<\n    STARTING SUBSCRIBER. ...\n>>  S  <<\n");
	start_thread(subscribe);

	run();
	
	return 0;
}
