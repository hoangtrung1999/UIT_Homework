//2.18
import numpy as np

def nextp(distance, S):
    point = 0
    min = np.max(distance) + 1
    for i in range(len(distance)):
        if distance[S][i] > 0 and distance[S][i] < min:
            min = distance[S][i]
            point = i
    for i in range(len(distance)):
        distance[S][i] = -1
        distance[i][S] = -1
    return distance, point
    
def find(distance, S):
    route = [S]
    for i in range(len(distance) - 1):
        distance, point = nextp(distance, S)
        S = point
        route.append(S)
    return route
    
distance = np.array([[-1, 17, 10, 9, 12], [17, -1, 8, 14, 5], [10, 8, -1, 7, 11], [9, 14, 7, -1, 11], [12, 5, 11, 11, -1]])
S = int(input())
a = find(distance, S)
a.append(S)
print(a)