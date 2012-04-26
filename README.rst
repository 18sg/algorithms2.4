Algorithms Coursework: Small-World Network Average Path Lengths
===============================================================

To compile::
	scons
This gives you a binary ``main``. This currently spits out a graphviz
description of a small-world network. You might want to render this using::
	./main > /tmp/graph
	circo /tmp/graph -Tpng > /tmp/graph.png 
	eog /tmp/graph.png
Lovely-jubbly!

Currently implemented
---------------------

* Digraph representation where nodes have fixed out-degrees ``digraph.{c,h}``
* Small-world graph generator ``small_world.{c,h}``
* Main program file which can be used to test/observe the small-world generator.
  See the code for usage info.

Digraph representation
``````````````````````

See the header file for usage.


Small-world generator
`````````````````````

Generates small-world networks within a digraph described above. Small-world
networks are not directional and so you must convert the digraph into a normal
undirected graph representation. This task still needs doing ;)

The small-world generator is just one function. See the header for usage info.


Things TODO:
------------

Suggested allocations, sorry its so serial

* Chris: Graph representation (efficient for large, sparse graphs and searching
  with Dijkstra's algorithm).
* Karl: Dijkstra's algorithm
* Matt: Run experiments with big networks (maybe parallelism)
* Tom: Generates some interesting graphs from the results
* Poster: All of us (Jonathan will do the design bit if you wish)

