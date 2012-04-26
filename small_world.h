#ifndef SMALL_WORLD_H
#define SMALL_WORLD_H

#include "digraph.h"

/**
 * Generate a small world network starting with a ring network where each node is
 * connected to its k nearest neighbours. The links are swapped for random ones
 * with a probability b.
 */
void small_world_init(digraph_t *digraph, size_t k, double b);

#endif
