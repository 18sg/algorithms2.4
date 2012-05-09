#ifndef QUEUE_H
#define QUEUE_H

#include "packed_graph.h"

typedef struct queue_element queue_element;
struct queue_element
{
	queue_element* next;
	packed_node *node;
};

typedef struct
{
	queue_element* head;
	queue_element* tail;
	queue_element* free_head;
}queue; 

void queue_init(queue* q);
void queue_push_back(queue* q, packed_node *node);
int queue_has_elements(queue* q);
packed_node *queue_pop(queue* q);
void queue_destory(queue* q);

#endif
