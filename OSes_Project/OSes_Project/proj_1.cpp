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
 |		all requirements on q.h are met.			|
 +--------------------------------------------------+
 */
#include "q.hpp"

/**		This file should be compiled using "gcc proj_1.c"		**/

int main() {
	struct q *Queue;	// this is our queue pointer
	struct q head;
	Queue = (struct q *) malloc(sizeof(struct q));

	Queue->init(head);
	Queue->print();

	return 0;
}

/*
								SUPPORT FUNCTIONS
*/
