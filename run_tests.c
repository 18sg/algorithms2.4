#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <time.h>
#include "digraph.h"
#include "packed_graph.h"
#include "small_world.h"
#include "dijkstra.h"
#include "stats.h"
#include "bfs.h"

typedef struct {
	size_t n;
	size_t k;
	double b;
} params;

typedef struct {
	stats s;
	params p;
	double time;
} info;

stats get_stats(params p)
{
	digraph_t digraph;
	digraph_init(&digraph, p.n, p.k);
	small_world_init(&digraph, p.k, p.b);
	
	packed_graph *graph = digraph_to_packed(&digraph);

	stats s = find_stats_for_graph(graph, 1);

	digraph_free(&digraph);
	packed_free(graph);
	
	return s;
}

info get_info(params p)
{
	clock_t time_start = clock();
	
	stats s = get_stats(p);
	
	return (info){
		.s = s,
		.p = p,
		.time = (double)(clock() - time_start) / CLOCKS_PER_SEC};
}

void print_header(void)
{
	printf("num_nodes,out_degree,randomisation,L,max_dist,total_dist,time\n");
}

void print_info(info i)
{
	printf("%zd,%zd,%f,%f,%llu,%llu,%f\n",
		i.p.n, i.p.k, i.p.b,
		(double)i.s.total_distance / (double)i.s.num_paths,
		i.s.max_distance, i.s.total_distance,
		i.time);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	print_header();
	for (int n = 200; n <= 10000; n += 200) {
		for (int k = 1; k <= 20; k++) {
			for (int b = 0; b <= 100; b += 5) {
				print_info(get_info((params){n, k, (double)b / 100.0}));
			}
		}
	}
}
