#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "graph.h"
#include "stats.h"

int total_dist = 0;
double average_distance = 0;
int non_reachable_nodes = 0;
int max_distance = 0;

void get_stats(graph_t *g)
{
	int i;
	for (i = 1; i < g->num_nodes; ++i)
	{
		// count unreachable nodes and total distances
		if (g->nodes[i].distance == g->num_nodes + 1)
			non_reachable_nodes++;
		else
			total_dist += g->nodes[i].distance;
		
		// remember max disatnce
		if (g->nodes[i].distance > max_distance && g->nodes[i].distance != g->num_nodes + 1) {
			max_distance = g->nodes[i].distance;
		}
	}
}

void stats_fprint( FILE* stream, graph_t *graph)
{
	double nodes_squared = (pow(graph->num_nodes, 2) - graph->num_nodes);
	
	fprintf(stream, "Max distance: %d\n", max_distance);
	fprintf(stream, "Total path length: %d\n", total_dist);
	fprintf(stream, "Average path length (L): %f\n",
			(double)total_dist / (nodes_squared - non_reachable_nodes));
}
