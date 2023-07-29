import sys
from collections import deque


def bfs(gp, v, visited):
    ckpt = dict()
    que = deque(gp[v])
    visited[v] = True
    ckpt.update({v:1})
    while que:
        r = que.popleft()
        ckpt.update({r:1})
        for i in gp[r]:
            ckpt.update({i:1})
            if not visited[i]:
                que.append(i)
                visited[i] = True
    return ckpt

input = sys.stdin.readline
n = int(input())
m = int(input())
gp = [[] for _ in range(n+1)]
visited = [False]*(n+1)

for _ in range(m):
    u,v = map(int, input().split())
    gp[u].append(v)
    gp[v].append(u)

ckpt = bfs(gp,1,visited)
del ckpt[1]
print(sum(ckpt.values()))