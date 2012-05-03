#ifndef STATS_H
#define STATS_H

/**
 * Some relevant values for stats
 */
int total_dist;
double average_distance;
int non_reachable_nodes;
int max_distance;

/*
 * Fills the above values in.
 * get_stats() can be called multiple times to accumulate stats
 * stats_fprint() does what it says on the tin
 */
void get_stats(graph_t *);
void stats_fprint(FILE *, graph_t *);

#endif
