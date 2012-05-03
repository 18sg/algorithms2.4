#ifndef PQUEUE_H
#define PQUEUE_H

node_t **queue;
int q_size;

void queue_setup(graph_t *);
int h_parent_of(int);
int h_child_of(int);
void h_upheap(int);
void push(node_t *);
void h_downheap(int);
node_t *pop();

#endif
