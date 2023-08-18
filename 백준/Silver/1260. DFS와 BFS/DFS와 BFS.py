import sys
from collections import deque

input = sys.stdin.readline


def dfs(s_p):
    visited[s_p] = 1
    print(s_p, end=' ')
    for next_i in gp[s_p]:
        if not visited[next_i]:
            dfs(next_i)


def bfs(s_p):
    visited_q = [0] * (n+1)
    q = deque()
    q.append(s_p)
    visited_q[s_p] = 1
    while q:
        t = q.popleft()
        print(t, end=' ')
        for next_i in gp[t]:
            if not visited_q[next_i]:
                q.append(next_i)
                visited_q[next_i] = visited_q[t] + 1


n, m, r = map(int, input().split())
gp = [[] for _ in range(n+1)]
visited = [0] * (n+1)
for _ in range(m):
    u, v = map(int, input().split())
    gp[u].append(v)
    gp[v].append(u)

for i in range(1, n+1):
    gp[i].sort()

dfs(r)
print()
bfs(r)
print()