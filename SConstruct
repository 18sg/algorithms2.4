env = Environment(parse_flags = '-lm')
env.Append(CCFLAGS = "-g -std=c99 -Wall -fopenmp")
env.Append(LINKFLAGS = "-fopenmp")
env.Program(["main.c", "small_world.c", "digraph.c", "graph.c", "queue.c", "bfs.c", "stats.c"])
env.Program(["dijkstra_test.c", "small_world.c", "digraph.c", "graph.c", "dijkstra.c", "pqueue.c", "stats.c", "bfs.c", "queue.c"])
