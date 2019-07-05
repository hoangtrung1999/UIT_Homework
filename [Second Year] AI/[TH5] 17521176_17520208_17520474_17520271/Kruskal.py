import numpy as np

# Input
distance = np.loadtxt('graph2_test.txt', dtype=int)

# Indexes of edges in ascending order
sorted_idx = np.unravel_index(np.argsort(distance, axis=None, kind='stable'), distance.shape)
sorted_idx = np.stack(np.array(sorted_idx), axis=-1)

# Remove similar half of symmetric matrix
# Number of vertex
n = distance.shape[0]
# Remove 0 points
n_zero = distance.size - np.count_nonzero(distance)
remove = [i for i in range(n_zero)]
for i in range(n_zero, sorted_idx.shape[0]):
    for j in range(i+1, sorted_idx.shape[0]):
        # (1,2) and (2,1) point to the same value
        if np.array_equal(sorted_idx[i], np.flip(sorted_idx[j])):
            remove.append(j)
sorted_idx = np.delete(sorted_idx, remove, axis=0)

min_span_tree = np.empty((n - 1, 2), dtype=int)
# Degree table
degree = np.zeros(n, dtype=int)
# Current number of edge in tree
count = 0


# Check if exists a path in tree
def check_route(tree, start, stop):
    avail_edge = np.where(tree == start)[0]
    # Dead end
    if avail_edge.size == 0:
        return False
    # Destination reached
    elif np.where(tree[avail_edge] == stop)[0].size != 0:
        return True

    # Cut off the path traversed
    subtree = np.delete(tree, avail_edge, axis=0)
    # Test available path
    for i in avail_edge:
        if tree[i, 0] == start:
            check = tree[i, 1]
        else:
            check = tree[i, 0]
        if check_route(subtree, check, stop):
            return True
    # No path to reach destination
    return False


for i in sorted_idx:
    # If vertex is not in tree yet
    if degree[i[0]] == 0 or degree[i[1]] == 0:
        degree[i] += 1
        min_span_tree[count] = i
        count += 1
    else:
        # Check if new edge will make subroute or not
        # The less paths available is chosen to reduce cost
        if degree[i[0]] < degree[i[1]]:
            check = check_route(min_span_tree[:count], i[0], i[1])
        else:
            check = check_route(min_span_tree[:count], i[1], i[0])
        if not check:
            degree[i] += 1
            min_span_tree[count] = i
            count += 1

        # Tree has all vertices
        if count == n - 1:
            break

print(min_span_tree)