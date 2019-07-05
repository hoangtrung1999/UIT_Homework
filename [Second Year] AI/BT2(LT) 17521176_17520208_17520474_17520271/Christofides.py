import numpy as np
from collections import Counter

data = np.loadtxt('132.txt', dtype=int)

a = np.copy(data)
idx = np.unravel_index(np.argsort(a, axis=None, kind='stable'), a.shape)
n = a.shape[0]

idx = np.stack(np.array(idx), axis=-1)
remove = [i for i in range(n)]
for i in range(n, idx.shape[0]):
    for j in range(i+1, idx.shape[0]):
        if np.array_equal(idx[i], np.flip(idx[j])):
            remove.append(j)
idx = np.delete(idx, remove, axis=0)

# Kruskal
vertex_table = np.zeros(n, dtype=int)
min_span_tree = np.empty((n - 1, 2), dtype=int)
count = 0


def check_route(tree, start, stop):
    temp = np.where(tree == start)[0]
    if temp.size == 0:
        return False
    elif np.where(tree[temp] == stop)[0].size != 0:
        return True

    subtree = np.delete(tree, temp, axis=0)
    for i in temp:
        if tree[i, 0] == start:
            check = tree[i, 1]
        else:
            check = tree[i, 0]
        if check_route(subtree, check, stop):
            return True

    return False


for i in idx:
    if vertex_table[i[0]] == 0 or vertex_table[i[1]] == 0:
        vertex_table[i] += 1
        min_span_tree[count] = i
        count += 1
    else:
        if vertex_table[i[0]] < vertex_table[i[1]]:
            check = check_route(min_span_tree[:count], i[0], i[1])
        else:
            check = check_route(min_span_tree[:count], i[1], i[0])
        if not check:
            vertex_table[i] += 1
            min_span_tree[count] = i
            count += 1

        if count == n:
            break


# Heuristic find minimum sum
odd_table = np.array(np.where(vertex_table % 2 != 0))[0]

for i in idx:
    if i[0] in odd_table and i[1] in odd_table:
        min_span_tree = np.append(min_span_tree, [i], axis=0)
        odd_table = np.delete(odd_table, np.where(np.isin(odd_table, i)))
        if odd_table.shape == 0:
            break

# Euler Tour
start = 1
current_pos = start
tour = []

while min_span_tree.shape[0] != 0:
    loc = np.where(min_span_tree == current_pos)[0][0]
    tour.append(current_pos)
    if min_span_tree[loc, 0] == current_pos:
        current_pos = min_span_tree[loc, 1]
    else:
        current_pos = min_span_tree[loc, 0]
    min_span_tree = np.delete(min_span_tree, loc, axis=0)

tour.append(start)

# Hamilton Tour
counter = Counter(tour)
for i in counter:
    if i != start and counter[i] == 2:
        j = tour.index(i)
        k = tour.index(i, j+1)
        if a[j-1, j+1] < a[k-1, k+1]:
            tour.pop(j)
        else:
            tour.pop(k)


print("Chu trinh ngan nhat la ", end=' ')
for i in tour:
    print(i, end=' ')