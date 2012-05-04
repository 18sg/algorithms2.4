#include <limits.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "stats.h"
#include "bfs.h"

stats find_stats_for_graph(graph_t* graph, int execute_in_parallel)
{
	// By default we will execute serially.
	int no_threads_to_use = 1;
	if(execute_in_parallel == 1)
	{
		// If we want to execute in parallel, then we pass OpenMP
		// 0 threads as this will spawn a number of threads that equates
		// to the number of logical CPUs on the system.
		no_threads_to_use = 0;
	}
	stats the_stats;
	int total_distance = 0;
	int num_paths = 0;
	int shared_max_distance = 0;
	int local_max_distance;
	int* disti;
	#pragma omp parallel private(disti, local_max_distance) shared(shared_max_distance) \
		num_threads(no_threads_to_use)reduction(+:total_distance, num_paths)
	{
		local_max_distance = 0;
		disti = calloc(sizeof(*disti), graph->num_nodes);
		#pragma omp for
		for(int i = 0; i < graph->num_nodes; i++)
		{
			bfs(graph, i, disti);

			for(int j = 0; j < graph->num_nodes; j++)
			{
				if(j != i && disti[j] != INF)
				{
					total_distance += disti[j];
					num_paths++;
					if(disti[j] > local_max_distance)
					{
						local_max_distance = disti[j];
					}
				}
			}
		}
		free(disti);
		#pragma omp critical
		{
			if(local_max_distance > shared_max_distance)
				shared_max_distance = local_max_distance;
		}
	}

	the_stats.max_distance = shared_max_distance;
	the_stats.num_paths = num_paths;
	the_stats.total_distance = total_distance;

	return the_stats;
}



void bfs(graph_t* graph, int sauce, int distances[])
{
	queue q;
	queue_init(&q);

	for(int i = 0; i < graph->num_nodes; i++)
	{
		distances[i] = INF;
	}
	distances[sauce] = 0;

	queue_push_back(&q, sauce);

	while(queue_has_elements(&q))
	{
		int idx = queue_pop(&q);
		edge_t* adj_list = graph->nodes[idx].edge_list;

		while(adj_list != NULL)
		{
			node_t* adj_node = adj_list->target;
			int adjidx = adj_node - graph->nodes;
			if(distances[adjidx] == INF)
			{
				distances[adjidx] = distances[idx] + 1;
				queue_push_back(&q, adjidx);
			}
			adj_list = adj_list->next;
		}
	}
	queue_destory(&q);
}
