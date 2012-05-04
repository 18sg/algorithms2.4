#include <assert.h>
#include <stdlib.h>
#include "queue.h"

void queue_init(queue* q)
{
	q->head = NULL;
	q->tail = NULL;
	q->free_head = NULL;
}

void queue_push_back(queue* q, int idx)
{
	queue_element* new_element;
	if(q->free_head != NULL)
	{
		new_element = q->free_head;
		q->free_head = new_element->next;
	}
	else
	{
		new_element = malloc(sizeof(*new_element));
	}

	new_element->idx = idx;
	new_element->next = NULL;

	if(q->head == NULL)
	{
		q->head = new_element;
		q->tail = new_element;
	}
	else
	{
		q->tail->next = new_element;
		q->tail = new_element;
	}
}

int queue_has_elements(queue* q)
{
	return (q->head != NULL);
}

int queue_pop(queue* q)
{
	assert(queue_has_elements(q));

	queue_element* t_element;
	t_element = q->head;

	q->head = t_element->next;
	if(q->head == NULL)
	{
		q->tail = NULL;
	}
	t_element->next = q->free_head;
	q->free_head = t_element;

	return t_element->idx;
}

void queue_destory(queue* q)
{
	queue_element* t = q->head;
	while(t != NULL)
	{
		queue_element *next = t->next;
		free(t);
		t = next;
	}
	
	t = q->free_head;
	while(t != NULL)
	{
		queue_element *next = t->next;
		free(t);
		t = next;
	}
}
