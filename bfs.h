#ifndef __BFS_H_
#define __BFS_H_
#include "stats.h"
stats find_stats_for_graph(graph_t* graph, int execute_in_parallel);
void bfs(graph_t* graph, int sauce, int distances[]);
#endif

