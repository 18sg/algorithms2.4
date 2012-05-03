#include <limits.h>
#include "dijkstra.h"
#include "pqueue.h"
#include "graph.h"

void dijkstra(graph_t *g, int source)
{
	node_t *u;
	
	int i;
	// reset fields -- needed for the stats thing because we're going through
	// the graph g->num_nodes times
	for (i = 0; i < g->num_nodes; ++i) {
		g->nodes[i].distance = g->num_nodes + 1;
		g->nodes[i].visited = false;
	}
	
	// pick out the source element
	u = &(g->nodes)[source];
	u->distance = 0;
	u->visited = true;
	// push it onto the priority queue
	push(u);
	
	// while there are still elements in the priority queue
	while (q_size > 0) {
		// if the distance of the best element in the queue is infinity, stop
		if (queue[0]->distance == g->num_nodes + 1)
			break;
		
		// pop the best element
		u = pop();
		// get its adjancency list
		edge_t *adj_list = u->edge_list;
		node_t *adj_node;
		
		
		// while there are still adjacent nodes
		while (adj_list != NULL) {
			// hold the adjancent node in a tmp variable
			//adj_node = &g->nodes[adj_list->index];
			adj_node = adj_list->target;
			
			// if the distance + 1 of the best element is less than the distance of the
			// adjancent node
			if ((u->distance + 1) < adj_node->distance) {
				// update the distance and previous
				adj_node->distance = (u->distance) + 1;
			}// if
			
			// add it onto the heap, if it's not been visited before
			if (!adj_node->visited) {
				adj_node->visited = true;
				push(adj_node);
			}// if
			
			// get the next adjacent item
			adj_list = adj_list->next;
			
		}// while
	}// while
}// dijkstra()

