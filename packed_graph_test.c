#include <assert.h>
#include "packed_graph.h"
#include "digraph.h"
#include "small_world.h"

// Check that the new graph has the same number of edges, and that
// packed_has_edge is consistent. This could pass with a completely borked
// digraph_to_packed function, but it's too dificult to test.

int main() {
	digraph_t digraph;
	
	size_t n = 20;   // Number of nodes
	size_t k = 2;    // Distance of furthest neighbour
	double b = 0.5;  // Small-world Randomisation
	
	digraph_init(&digraph, n, k);
	
	small_world_init(&digraph, k, b);
	
	packed_graph *g = digraph_to_packed(&digraph);
	
	int no_edges = 0;
	for (packed_node *node = g->nodes[0]; !PACKED_END(node); node = PACKED_NEXT(node)) {
		for (int edge_no = 0; edge_no < node->degree; edge_no++) {
			assert(packed_has_edge(node, node->edges[edge_no]));
			assert(packed_has_edge(node->edges[edge_no], node));
			no_edges++;
		}
	}
	
	assert(no_edges == digraph.num_nodes * digraph.out_degree * 2);
}

