#ifndef STATS_H
#define STATS_H

typedef struct
{
	long total_distance;
	long max_distance;
	long num_paths;
}stats;

/*
 * Fills the above values in.
 * get_stats() can be called multiple times to accumulate stats
 * stats_fprintf() does what it says on the tin
 */
void stats_init(stats* stats);
void stats_accumulate(stats* stats, graph_t* graph, int source, int distances[]);
void stats_fprintf(stats* stats, graph_t* graph, FILE* buf);
#endif
