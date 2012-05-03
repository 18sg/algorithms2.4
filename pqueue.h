#ifndef PQUEUE_H
#define PQUEUE_H

node_t **queue;
int q_size;

/**
 * Internal queue functions
 */
int h_parent_of(int);
int h_child_of(int);
void h_upheap(int);
void h_downheap(int);

/**
 * Functions part of the API.
 * queue_setup() to allocate space
 * queue_free() to free the space up
 * push() to push an element to the queu
 * pop() to pop the best one off
 */
void queue_setup(graph_t *);
void queue_free(void):
void push(node_t *);
node_t *pop();

#endif
