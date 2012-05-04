#include "graph.h"

#include <stdlib.h>

bool edge_list_contains(edge_t *edge, node_t *target)
{
	if (edge == NULL)
		return false;
	else if (edge->target == target)
		return true;
	else
		return edge_list_contains(edge->next, target);
}

bool edge_list_add( edge_t** edge, node_t* target )
{
	if( target == NULL || edge == NULL )
	{
		return false;
	}
	else if( *edge == NULL )
	{
		edge_t* new_edge = ( edge_t* ) malloc( sizeof( edge_t ) );
		new_edge->target = target;
		new_edge->next = NULL;
		*edge = new_edge;
		return true;
	}
	else
	{
		return edge_list_add( &( ( *edge )->next ), target );
	}
}

void graph_init( graph_t* graph, int num_nodes )
{
	graph->num_nodes = num_nodes;
	graph->nodes = ( node_t* ) malloc( sizeof( node_t ) * num_nodes );
	int i;
	for( i = 0; i < num_nodes; ++i )
	{
		graph->nodes[i].value = i;
		graph->nodes[i].edge_list = NULL;
	}
}

void graph_fprint( FILE* stream, graph_t* graph )
{
	fprintf( stream, "graph g {\n\tnode [shape=\"point\"];\n" );
	int i;
	for( i = 0; i < graph->num_nodes; ++i )
	{
		edge_t* current = graph->nodes[i].edge_list;
		while( current )
		{
			// Only print edges in one direction			
			if (current->target <= &(graph->nodes[i]))
				fprintf( stream, "\t%d -- %d;\n", graph->nodes[i].value, current->target->value );
			current = current->next;
		}
	}
	fprintf( stream, "}\n" );
}

void graph_destory(graph_t* graph)
{
	for(int i =0; i < graph->num_nodes; i++)
	{
		edge_t* edge = graph->nodes[i].edge_list;
		while(edge != NULL)
		{
			edge_t* temp_edge = edge->next;
			free(edge);
			edge = temp_edge;
		}
	}
	free(graph->nodes);
}
