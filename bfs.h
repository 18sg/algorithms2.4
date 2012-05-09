#ifndef __BFS_H_
#define __BFS_H_
#include "stats.h"
#include "packed_graph.h"
stats find_stats_for_graph(packed_graph* graph, int execute_in_parallel);
void bfs(packed_graph* graph, int sauce, int distances[]);
#endif

