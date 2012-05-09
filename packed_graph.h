#ifndef PACKED_GRAPH_H
#define PACKED_GRAPH_H

#include "digraph.h"

// In this graph representation, the entire graph is represented by a single
// block of memory. Each node is packed in order, and takes up a variable
// ammount of space, depending on the number of edges incident at it.

// It is possible to get to the next node in the sequence using the PACKED_NEXT
// macro, and there is a terminating node, which can be detected by the
// PACKED_END macro.

typedef struct packed_node {
	int degree;
	int idx;
	struct packed_node *edges[];
} packed_node;

// packed_graph stores the number of nodes, as well as a pointer to each node.

typedef struct {
	int num_nodes;
	packed_node **nodes;
} packed_graph;

// Convert a digraph into a packed representation.
packed_graph *digraph_to_packed(digraph_t *digraph);

// Is there an edge from left to right?
bool packed_has_edge(packed_node *left, packed_node *right);

// Freew a packed graph.
void packed_free(packed_graph *g);

// Get a pointer to the next node in the chain.
#define PACKED_NEXT(n) ((packed_node *)(n->edges + n->degree))
// Have we iterated past the end of the nodes?
#define PACKED_END(n) (n->degree == -1)

#endif
