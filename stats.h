#ifndef STATS_H
#define STATS_H

#include "packed_graph.h"

typedef struct
{
	unsigned long long total_distance;
	unsigned long long max_distance;
	unsigned long long num_paths;
}stats;

/*
 * Fills the above values in.
 * get_stats() can be called multiple times to accumulate stats
 * stats_fprintf() does what it says on the tin
 */
void stats_init(stats* stats);
void stats_accumulate(stats* stats, packed_graph* graph, int source, int distances[]);
void stats_fprintf(stats* stats, packed_graph* graph, FILE* buf);
#endif
