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

# At the beginning, all the other nodes in the graph are considered to be at infinite distance from the source node,
# because the distance has not been determined yet.


def shortest_path_for(graph, start):
    unvisited = []
    distances = {}
    for node in graph:
        unvisited.append(node)
        if node == start:
            distances[node] = 0
        else:
            distances[node] = float('inf')
    print(f'Unvisited: {unvisited}\nDistances: {distances}')


# The list() type constructor enables you to build a list from an iterable.
def shortest_path_list(graph, start):
    unvisited = list(graph)
    distances = {node: 0 if node == start else float('inf') for node in graph}
    paths = {key: [] for key in graph}
    paths[start].append(start)
    while unvisited:
        current = min(unvisited, key=distances.get)
        for node, distance in graph[current]:
            pass
    print(f'Unvisited: {unvisited}\nDistances: {distances}\nPaths: {paths}')


# shortest_path_list(my_graph, 'A')

