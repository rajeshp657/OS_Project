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
#include "q.hpp"

/**		This program should be compiled using "gcc proj_1.c"		**/

/*
								SUPPORT FUNCTIONS
*/

// prints the payload value of each queue element
// assumes that the pointer passed is a pointer to the head of the queue
void print_element(struct q &q_element) {
	if (DEBUG) {
		using namespace std;

		cout << "+----------+----+" << endl;
		cout << "| payload: | " << q_element.payload << endl;
		cout << "+----------+---------+" << endl;
		cout << "+   head:  | " << &*q_element.head << endl;
		cout << "+   prev:  | " << &*q_element.prev << endl;
		cout << "+   next:  | " << &*q_element.next << endl;
		cout << "+----------+---------+" << endl;
	}
}

int main() {
	using namespace std;

	struct q Queue = {};	// this is an empty queue for testing
	
	struct q someHead = {};	// a random q-element

	Queue.init(someHead);
	print_element(Queue);

	return 0;
}

