#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "graph.h"
#include "stats.h"

void stats_init(stats* s)
{
	*s = (stats){0,0,0};
}

void stats_accumulate(stats* stats, graph_t* graph, int source, int distances[])
{
 	for(int i = 0; i < graph->num_nodes; i++)
	{
		if(i != source && distances[i] != INF)
		{
			stats->total_distance += distances[i];
			stats->num_paths++;
			if(distances[i] > stats->max_distance)
			{
				stats->max_distance = distances[i];
			}
		}
	}
}

void stats_fprintf(stats* stats, graph_t* graph, FILE* stream)
{
	fprintf(stream, "Max distance: %ld\n", stats->max_distance);
	fprintf(stream, "Total path length: %ld\n", stats->total_distance);
	fprintf(stream, "Average path length (L): %f\n",
	        (double)stats->total_distance / (double)stats->num_paths);
}
