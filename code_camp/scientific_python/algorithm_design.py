# use a dictionaries to represent graphs
# A graph is a non-linear data structure, which consists of vertices(or nodes) connected by edges(or arcs)
# where edges may be directed or undirected.
# the keys represent the current node and the values represent to what node OR nodes are connected the current node
# in the next example is the representation of a graph A-B-C-D
my_graph_or = {
    'A': ['B', 'D'],
    'B': ['A', 'C'],
    'C': ['B', 'D'],
    'D': ['A', 'C']
}

# weighed graph (tuples inside lists) and represents the distances between the nodes
my_graph = {
    'A': [('B', 3), ('D', 1)],
    'B': [('A', 3), ('C', 4)],
    'C': [('B', 4), ('D', 7)],
    'D': [('A', 1), ('C', 7)]
}

# The algorithm will start at a specified node.
# Then it will explore the graph to find the shortest path between the starting node,
# or source, and all the other nodes.


def shortest_path(graph, start):
    unvisited = []
    distances = {}
    for node in graph:
        unvisited.append(node)
        if node == start:
            distances[node] = 0
