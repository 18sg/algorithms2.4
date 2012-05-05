#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include "digraph.h"
#include "graph.h"
#include "small_world.h"
#include "dijkstra.h"
#include "stats.h"
#include "bfs.h"

void print_useage(char* prog_name)
{
	printf("Useage:\n");
	printf("%s [-n nodes] [-k distance] [-b rand] [-p]\n", prog_name);
	printf("\n");
	printf("-n: The number of nodes in the graph.\n");
	printf("-k: The distance of the furthest neighbour.\n");
	printf("-b: The small-world randomisation "
	       "(shuold be a float in the interval (0, 1).\n");
	printf("-p: Whether to use parallelisation for graph processing.\n");

}

int main(int argc, char *argv[])
{
	digraph_t digraph;
	size_t n = 20;   // Number of nodes
	size_t k = 2;    // Distance of furthest neighbour
	double b = 0.5;  // Small-world Randomisation
	int parallelise = 0;
	int opt;
	while((opt = getopt(argc, argv, "n:k:b:p")) != -1)
	{
		switch(opt)
		{
			case 'n':
				n = atoi(optarg);
				break;
			case 'k':
				k = atoi(optarg);
				break;
			case 'b':
				b = atoi(optarg);
				break;
			case 'p':
				parallelise = 1;
				break;
			default:
				print_useage(argv[0]);
				exit(-1);
		}
	}

	digraph_init(&digraph, n, k);
	small_world_init(&digraph, k, b);
	//digraph_fprint(stdout, &digraph);

	graph_t graph;


	graph_init( &graph, ( &digraph )->num_nodes );

	small_world_to_graph( &digraph, &graph );

	stats s = find_stats_for_graph(&graph, parallelise);

	stats_fprintf(&s, &graph, stdout);

	digraph_free(&digraph);
	graph_destory(&graph);

	return 0;
}
