import numpy as np

'''
Prim's Minimum Spanning Tree
1) Create a set mstSet that keeps track of vertices already included in the input graph.
2) Assign a key value to all vertices in the input graph. Initialize all key values as INF.
Assign key value as 0 for the first vertex so that it is picked first.
3) While mstSet doesn't include all vertices:
- Pick a vertex u which is not there in mstSet and has minimum key value.
- Add u to mstSet.
- Update key value of all adjacent vertices of u.
For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v,
update the key value as weight u-v.
'''

def minKey(key, mstSet):
    minIndex = np.argmax(key)
    for i in range(len(key)):
        if i not in mstSet and key[i] < key[minIndex]:
            minIndex = i
    return minIndex


if __name__ == "__main__":
    # Load graph
    graph = np.loadtxt("graph2_test.txt")
    # Save the shape of it
    n = graph.shape[0]
    # Create a empty set that keeps track of vertices already included in the input graph.
    mstSet = []
    # Create a parent set to track which edge connects from u to v
    parent = [0] * n
    # The first vertex is parent to itself
    parent[0] = -1
    # Create and assign a key value to all vertices in the input graph.
    # Also assign 0 for the first vertex so that it is picked first.
    key = np.array([float("Inf")] * n)
    key[0] = 0
    
    # While mstSet doesn't include all vertices
    while len(mstSet) < n:
        u = minKey(key, mstSet)
        # Add vertex that is not in mstSet and has minimum key value to mstSet
        mstSet.append(u)
        # Update key value of all adjacent vertices of u
        for v in range(n):
            if graph[u][v] != 0 and graph[u][v] < key[v] and v not in mstSet:
                key[v] = graph[u][v]
                parent[v] = u
    
    # Print minimum spanning tree
    print("Edge \tWeight")
    for i in range(1, n):
        print("%d - %d \t%3d" %(parent[i], i, graph[i][parent[i]]))