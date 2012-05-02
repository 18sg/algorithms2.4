#include <stdlib.h>
#include "small_world.h"

#define RAND_DBL() ((double)rand() / (double)RAND_MAX)


void small_world_init(digraph_t *digraph, size_t k, double b)
{
	int i;
	int neighbour;
	
	// Create a ring network
	for (i = 0; i < digraph->num_nodes; i++)
		for (neighbour = 0; neighbour < k; neighbour++)
			DG_NODE(digraph, i, neighbour) = (i + neighbour + 1) % digraph->num_nodes;
	
	// Small-worldify it
	for (neighbour = 0; neighbour < k; neighbour++) {
		for (i = 0; i < digraph->num_nodes; i++) {
			if (RAND_DBL() < b) {
				size_t random_node;
				
				do {
					random_node = rand() % digraph->num_nodes;
				} while (random_node == i // Don't make a self loop
				         // Don't duplicate edges
				         || digraph_has_edge(digraph, i, random_node)
				         || digraph_has_edge(digraph, random_node, i));
				
				DG_NODE(digraph, i, neighbour) = random_node;
			}
		}
	}
}

void small_world_to_graph( digraph_t* digraph, graph_t* graph )
{
	int i;
	int neighbour;
	
	for (i = 0; i < digraph->num_nodes; i++)
	{
		for (neighbour = 0; neighbour < digraph->out_degree; neighbour++)
		{
			if( !edge_list_contains( graph->nodes[i].edge_list, &( graph->nodes[DG_NODE(digraph, i, neighbour)] ) ) )
			{
				edge_list_add( &( graph->nodes[i].edge_list ), &( graph->nodes[DG_NODE(digraph, i, neighbour)] ) );
			}
			if( !edge_list_contains( graph->nodes[DG_NODE(digraph, i, neighbour)].edge_list, &( graph->nodes[i] ) ) )
			{
				edge_list_add( & (graph->nodes[DG_NODE(digraph, i, neighbour)].edge_list ), &( graph->nodes[i] ) );
			}

		}
	}
}
