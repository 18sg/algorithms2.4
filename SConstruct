env = Environment(parse_flags = '-lm')
env.Append(CCFLAGS = "-Ofast -g -std=c99 -Wall -fopenmp")
env.Append(LINKFLAGS = "-fopenmp")

env.Program(["run_test.c", "small_world.c", "digraph.c", "graph.c", "dijkstra.c", "pqueue.c", "stats.c", "bfs.c", "queue.c", "packed_graph.c"])
env.Program(["run_tests.c", "small_world.c", "digraph.c", "graph.c", "dijkstra.c", "pqueue.c", "stats.c", "bfs.c", "queue.c", "packed_graph.c"])

env.Program(["packed_graph_test.c", "packed_graph.c", "small_world.c", "digraph.c", "graph.c"])
