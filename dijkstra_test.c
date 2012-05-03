#include <stdio.h>
#include <stdlib.h>
#include "digraph.h"
#include "graph.h"
#include "small_world.h"
#include "dijkstra.h"
#include "stats.h"

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

	int i;
	for (i = 1; i < graph.num_nodes; ++i)
	{
		queue_setup(&graph);
		// do dijkstra on node i
		dijkstra(&graph, i);
		
		// accumulate stats
		get_stats(&graph);
		queue_free();
	}
	stats_fprint(stdout, &graph);
	

	digraph_free(&digraph);

	return 0;
}

