import sys
input = sys.stdin.readline
def find_set(x):
    if parents[x] == x:
        return x

    parents[x] = find_set(parents[x])
    return parents[x]
def union(x, y):
    x = find_set(x)
    y = find_set(y)

    if x == y:
        return

    if x < y:
        parents[y] = x
    else:
        parents[x] = y
V, E = map(int, input().split())
edges = []
for _ in range(E):
    u, v, w = map(int, input().split())
    edges.append([u, v, w])
edges.sort(key=lambda x: x[2])
parents = [i for i in range(V + 1)]
cnt = 0
sum_weights = 0
for u, v, w in edges:
    if find_set(u) != find_set(v):
        cnt += 1
        sum_weights += w
        union(u, v)
        if cnt == V:
            break
print(sum_weights)
