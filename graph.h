#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct edge;
struct node;
struct graph;

typedef struct edge
{
	struct node* target;
	struct edge* next;
} edge_t;

typedef struct node
{
	int value;
	int distance;
	bool visited;
	edge_t* edge_list;
} node_t;

typedef struct graph
{
	int num_nodes;
	node_t* nodes;
} graph_t;

bool edge_list_contains(edge_t *edge, node_t *target);
bool edge_list_add( edge_t** edge, node_t* target );
void graph_init( graph_t* graph, int num_nodes );
void graph_fprint( FILE* stream, graph_t* graph );

#endif
