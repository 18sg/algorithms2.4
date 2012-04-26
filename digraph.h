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


// Allocate memory for a digraph with the specified number of nodes, each with
// the given out-degree
void digraph_init(digraph_t *digraph, size_t num_nodes, size_t out_degree);

// Deallocate the digraph's memory
void digraph_free(digraph_t *digraph);

// Test if an edge exists from a node to a target
bool digraph_has_edge(digraph_t *digraph, size_t node, size_t target);

// Macro which gives (or can be used to assign to) the contents of the edge
// index e for node n.
//
// E.g. to set the 0th edge coming from node 4 to point to node 7:
//   digraph_t digraph;
//   ...
//   DG_NODE(&digraph, 4, 0) = 7;
#define DG_NODE(dg, n, e) ((dg)->graph[((n) * (dg)->out_degree) + (e)])

// Prints the digraph in graphviz format. Use circo to render these as PNGs.
void digraph_fprint(FILE *stream, digraph_t *digraph);

#endif
