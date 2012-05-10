CFLAGS=-Ofast -g -std=c99 -Wall -fopenmp
LDFLAGS=-fopenmp -lm

PROGRAMS=run_test run_tests packed_graph_test

all: $(PROGRAMS)

run_test: run_test.o small_world.o digraph.o graph.o dijkstra.o pqueue.o stats.o bfs.o queue.o packed_graph.o
run_tests: run_tests.o small_world.o digraph.o graph.o dijkstra.o pqueue.o stats.o bfs.o queue.o packed_graph.o

packed_graph_test: packed_graph_test.o packed_graph.o small_world.o digraph.o graph.o

.PHONY: clean
clean:
	rm -f $(PROGRAMS) *.o
