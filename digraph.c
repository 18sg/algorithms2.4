#include "digraph.h"


void digraph_init(digraph_t *digraph, size_t num_nodes, size_t out_degree)
{
	digraph->num_nodes  = num_nodes;
	digraph->out_degree = out_degree;
	digraph->graph      = malloc(num_nodes * out_degree * sizeof(void*));
}


void digraph_free(digraph_t *digraph)
{
	free(digraph->graph);
}


bool digraph_has_edge(digraph_t *digraph, size_t node, size_t target)
{
	size_t i;
	for (i = 0; i < digraph->out_degree; i++) {
		if (DG_NODE(digraph, node, i) == target)
			return true;
	}
	
	return false;
}


void digraph_fprint(FILE *stream, digraph_t *digraph)
{
	fprintf(stream, "digraph g {\n" 
	                "\tnode [shape=\"point\"];\n");
	size_t i;
	size_t j;
	for (i = 0; i < digraph->num_nodes; i++) {
		for (j = 0; j < digraph->out_degree; j++) {
			fprintf(stream, "\t%d -> %d;\n", i, DG_NODE(digraph, i, j));
		}
	}
	fprintf(stream, "}\n");
}
