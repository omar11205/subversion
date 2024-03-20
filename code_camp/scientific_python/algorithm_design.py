# use a dictionaries to represent graphs
# https://www.geeksforgeeks.org/building-an-undirected-graph-and-finding-shortest-path-using-dictionaries-in-python/
# https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
# https://www.geeksforgeeks.org/introduction-to-queue-data-structure-and-algorithm-tutorials/
# https://www.geeksforgeeks.org/fifo-first-in-first-out-approach-in-programming/
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
    'A': [('B', 5), ('C', 3), ('E', 11)],
    'B': [('A', 5), ('C', 1), ('F', 2)],
    'C': [('A', 3), ('B', 1), ('D', 1), ('E', 5)],
    'D': [('C', 1), ('E', 9), ('F', 3)],
    'E': [('A', 11), ('C', 5), ('D', 9)],
    'F': [('B', 2), ('D', 3)]
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
def shortest_path_list(graph, start, target=''):
    unvisited = list(graph)
    distances = {node: 0 if node == start else float('inf') for node in graph}
    paths = {key: [] for key in graph}
    paths[start].append(start)
    while unvisited:
        current = min(unvisited, key=distances.get)
        for node, distance in graph[current]:
            if distance + distances[current] < distances[node]:
                distances[node] = distance + distances[current]
                if paths[node] and paths[node][-1] == node:
                    paths[node] = paths[current][:]
                else:
                    paths[node].extend(paths[current])
                paths[node].append(node)
        unvisited.remove(current)

    targets_to_print = [target] if target else graph
    for node in targets_to_print:
        if node == start:
            continue
        print(f'\n{start}-{node} distance: {distances[node]}\nPath: {" -> ".join(paths[node])}')

    return distances, paths


shortest_path_list(my_graph, 'A', "F")

