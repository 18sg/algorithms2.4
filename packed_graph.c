#include "packed_graph.h"
#include <stdlib.h>

// Convert a digraph into a packed representation.
packed_graph *digraph_to_packed(digraph_t *digraph)
{
	// The degree of each node.
	int *degrees = calloc(digraph->num_nodes, sizeof(*degrees));
	
	// Populate the above array. Each node has at least out_degree edges, plus
	// all edges pointing at it.
	for (int node = 0; node < digraph->num_nodes; node++) {
		degrees[node] += digraph->out_degree;
		for (int out_edge = 0; out_edge < digraph->out_degree; out_edge++)
			degrees[DG_NODE(digraph, node, out_edge)]++;
	}
	
	// Pointers to the nodes of the new graph.
	packed_node **nodes = malloc(sizeof(*nodes) * digraph->num_nodes);
	
	// Pointer to the next available space.
	char *next = malloc((digraph->num_nodes + 1) * sizeof(packed_node)
	                    + digraph->num_nodes * digraph->out_degree * 2
	                      * sizeof(packed_node*));
	
	// Allocate and initialise the nodes.
	for (int node = 0; node < digraph->num_nodes; node++) {
		nodes[node] = (packed_node *)next;
		next += sizeof(packed_node) + degrees[node] * sizeof(packed_node*);
		// The degree is used here to tell us where to fill in the next edge.
		nodes[node]->degree = 0;
		nodes[node]->idx = node;
	}
	
	// Add the end marker.
	((packed_node *)next)->degree = -1;
	
	free(degrees);
	
	// For each edge in the digraph, add a pair of edges in the packed graph.
	for (int node = 0; node < digraph->num_nodes; node++) {
		packed_node *a = nodes[node];
		for (int out_edge = 0; out_edge < digraph->out_degree; out_edge++){
			packed_node *b = nodes[DG_NODE(digraph, node, out_edge)];
			
			a->edges[a->degree++] = b;
			b->edges[b->degree++] = a;
		}
	}
	
	// We're done with the nodes list; the graph is now represented by it's first node.
	packed_graph *graph = malloc(sizeof(*graph));
	graph->num_nodes = digraph->num_nodes;
	graph->nodes = nodes;
	
	return graph;
}

// Is there an edge from left to right?
bool packed_has_edge(packed_node *left, packed_node *right)
{
	for (int edge = 0; edge < left->degree; edge++)
		if (left->edges[edge] == right)
			return true;
	
	return false;
}

// Free a packed graph.
void packed_free(packed_graph *g)
{
	free(g->nodes[0]);
	free(g->nodes);
	free(g);
}
