import numpy as np

def dijkstra(graph, start, end):
    n = graph.shape[0]
    dist = np.array([float('inf')] * n) #init distance
    dist[start] = 0
    route = []
    flag = np.array([1] * n) #if vertex is taken out
    prev = [-1] * n #previous vertex of i
    
    while np.sum(flag) > 0:
        temp = np.copy(dist[np.nonzero(flag)]) #current graph
        u = np.argwhere(dist == np.min(temp)).reshape(-1)[0]  
        flag[u] = 0 #take vertex out of graph
        if u == end:  #if current vertex is end
            break
        for i in range(n):
            if graph[u][i] != 0:  #if there's edge
                alt = dist[u] + graph[u][i]
                if alt < dist[i]:
                    dist[i] = alt
                    prev[i] = u
        
    while u != start:
        route.append(u)  #append to route from end to start
        u = prev[u]
    route.append(start)
    return route[::-1], dist[end]

def through_vertex(graph, start, end, vertex):
    route1, _ = dijkstra(graph, start, vertex)
    route2, _ = dijkstra(graph, vertex, end)
    return route1 + route2[1:]

def through_edge(graph, start, end, vertex1, vertex2):
    if graph[vertex1][vertex2] == 0:
        print('Edge not found')
    else:
        graph[vertex1][vertex2] = 0
        route1, dist1 = dijkstra(graph, start, vertex1)
        route2, dist2 = dijkstra(graph, vertex2, end)
        route = route1 + route2
        dist = dist1 + dist2
        route1, dist1 = dijkstra(graph, start, vertex2)
        route2, dist2 = dijkstra(graph, vertex1, end)
        if dist > dist1 + dist2:
            route = route1 + route2
        return route

graph = np.array([[0, 20, 0, 0, 0, 0, 0], [20, 0, 42, 35, 60, 0, 0], [0, 42, 0, 40, 30, 0, 0], [0, 35, 40, 0, 0, 75, 0], [0, 60, 30, 0, 0, 55, 85], [0, 0, 0, 75, 55, 0, 45], [0, 0, 0, 0, 85, 45, 0]])

through_vertex(graph, 0, 3, 2)

through_edge(graph, 0, 4, 2, 5)

through_edge(graph, 0, 4, 2, 3)






