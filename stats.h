#ifndef STATS_H
#define STATS_H

int total_dist;
double average_distance;
int non_reachable_nodes;
double nodes_distance_5;
double nodes_distance_6;
int max_distance;

void get_stats(graph_t *);
void stats_fprint(FILE *, graph_t *);

#endif
