#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * A representation of a digraph where the out-degree of each node is fixed.
 */
typedef struct {
	// The number of nodes in the digraph
	size_t num_nodes;
	
	// The (fixed) out-degree of the digraph
	size_t out_degree;
	
	// The Graph itself. This is an array of arrays of size (out_degree *
	// num_nodes). The array is formatted as graph[node][edge] and contains the
	// node number that the selected edge points to.
	size_t *graph;
} digraph_t;


void digraph_init(digraph_t *digraph, size_t num_nodes, size_t out_degree);

void digraph_free(digraph_t *digraph);

bool digraph_has_edge(digraph_t *digraph, size_t node, size_t target);

#define DG_NODE(dg, n, e) ((dg)->graph[((n) * (dg)->out_degree) + (e)])

void digraph_fprint(FILE *stream, digraph_t *digraph);

#endif
