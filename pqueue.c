#include <stdlib.h>
#include "graph.h"
#include "pqueue.h"



/**
 * Set up the heap
 */
void queue_setup(graph_t *graph)
{
	q_size = 0;
	queue = calloc(graph->num_nodes, sizeof(node_t *));
}

void queue_free(void)
{
	free(queue);
}

/**
 * Find the parent-of
 */
int h_parent_of(int index)
{
	return (index - 1) / 2;
}


/**
 * Find the child-of
 */
int h_child_of(int index)
{
	return 2 * index + 1;
}


/**
 * Bubble up
 */
void h_upheap(int c_index)
{
	int current = c_index;
	int p_index = h_parent_of(c_index);
	node_t *tmp = queue[c_index];
	
	// while current is not out of bounds
	while (current > 0) {
		// if the distance of the element we're bubbling is less than the
		// distance of the one "above" it
		if (tmp->distance < queue[p_index]->distance) {
			// set the element at queue[current] to the value "above" it
			queue[current] = queue[p_index];
			
			// calculate new indecees
			current = p_index;
			p_index = h_parent_of(current);
		}
		// we've found the place to insert the element we're bubbling
		else
			break;
	}
	// insert the bubbling element
	queue[current] = tmp;
}


/**
 * push()
 */
void push(node_t *node)
{
	// push the new node as the last element
	queue[q_size] = node;
	// bubble it
	h_upheap(q_size);
	// increase queue size
	++q_size;
}


/**
 * Bubble down
 */
void h_downheap(int p_index)
{
	int current = p_index;
	int c_index = h_child_of(p_index);
	node_t *tmp = queue[p_index];
	
	// while child index is less than the queue size
	while (c_index < q_size) {
		// check bounds once again
		if (c_index < (q_size - 1))
			// if the distance of the right child is greater than
			// the distance of the left child, pick the right child
			if (queue[c_index + 1]->distance < queue[c_index]->distance)
				++c_index; // make the pick
		
		// if the distance of the bubbling element is greater than the element
		// "below" it
		if (tmp->distance > queue[c_index]->distance) {
			// make the element at queue[current] the one "below" it
			queue[current] = queue[c_index];
			
			// calculate new indecees
			current = c_index;
			c_index = h_child_of(current);
		}
		// we've found the place to insert the bubblig item, stop bubbling
		else
			break;
	}
	// insert the bubbling item
	queue[current] = tmp;
}


/**
 * pop()
 */
node_t *pop()
{
	// sanity check
	if (q_size < 1) return NULL;
	// take the best element out
	node_t *elem = queue[0];
	// put the last element in the front and decrease queue size
	queue[0] = queue[--q_size];
	// bubble the first element
	h_downheap(0);
	// return the best one
	return elem;
}
