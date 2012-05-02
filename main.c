#include <stdio.h>
#include <stdlib.h>
#include "digraph.h"
#include "graph.h"
#include "small_world.h"

int main(int argc, char *argv[])
{
	digraph_t digraph;
	
	size_t n = 20;   // Number of nodes
	size_t k = 2;    // Distance of furthest neighbour
	double b = 0.5;  // Small-world Randomisation
	
	digraph_init(&digraph, n, k);
	
	small_world_init(&digraph, k, b);
	//digraph_fprint(stdout, &digraph);

	graph_t graph;


	graph_init( &graph, ( &digraph )->num_nodes );

	small_world_to_graph( &digraph, &graph );

//	edge_list_add( &( graph.nodes[0].edge_list ), &( graph.nodes[0] ) );
//	printf( "%d\n", edge_list_contains( graph.nodes[0].edge_list, &( graph.nodes[0] ) ) );
//	printf( "%d\n", edge_list_contains( graph.nodes[1].edge_list, &( graph.nodes[0] ) ) );

	graph_fprint( stdout, &graph );

	digraph_free(&digraph);

	return 0;
}

