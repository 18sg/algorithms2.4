#include <stdio.h>
#include <stdlib.h>
#include "digraph.h"


int main(int argc, char *argv[])
{
	digraph_t digraph;
	
	size_t n = 20;   // Number of nodes
	size_t k = 2;    // Distance of furthest neighbour
	double b = 0.0;  // Small-world Randomisation
	
	digraph_init(&digraph, n, k);
	
	small_world_init(&digraph, k, b);
	digraph_fprint(stdout, &digraph);
	
	digraph_free(&digraph);
}

