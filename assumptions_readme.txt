assumptions_and_implementation_readme.txt

Compile: 
	"gcc proj-4.c"

	1. remove item conditions:
		- a new item must be read by all active subscribers

		- if no subscribers exist, the item waits in the buffer

		- an item waiting in the buffer is removed by a subscriber,
		once the subscriber has determined that all currently
		active subscribers have read the item

		- if the number of active subscribers is 1, the item will
		be removed from the buffer as soon as the single subscriber
		reads the item, the item does not wait for all 5 subscribers to read it,
		it only cares about the currently active subscribers

		- items deleted only require to be read by all subscribers 
		that are currently active at the time some subscriber is reading the item

	2. implementation:
		- to keep track of which subscribers have read which items, we created
		an integer array named subs[], to represent the set of subscribers

		- every item contains a unique subs[] array

		- initially subs[] looks like:
			[0, 0, 0, 0, 0] 
				-- where 0's represent "no subscriber exists at this index"

		- subscribers are given ID#'s that correlate to the index
		being used by subs[]
			-- Ex. subscriber[0] is represented by subs[0]

		- when an item has yet to be read by a particular subscriber,
		the subs[] array marks a 1, which means "this subscriber needs to read me"
			-- Ex. 	subscriber[1] & subscriber[2] both need to read this_item;
					this_item->subs[] looks like:
						[0, 1, 1, 0, 0]

		- after a subscriber reads an item, the subscriber marks the
		item's subs[] array with a 2, to represent "I have just read this item"
			-- Ex.	subscriber[2] has just read this_item;
					this_item->subs[] now looks like:
						[0, 1, 2, 0, 0]

		- after a subscriber reads and marks an item with a 2, the subscriber checks
		if the total number of 2's found in the item's subs[] array
		is equal to the total number of currently active subscribers (int sc),
		if true: 	remove the item from the buffer;
		else:		do nothing;

