import sys
sys.setrecursionlimit(10 ** 6)

input = sys.stdin.readline


def dfs(start):
    global cnt
    visited[start] = 1
    cnt += 1
    for i in gp[start]:
        if not visited[i]:
            dfs(i)


n = int(input())
m = int(input())
gp = [[] for _ in range(n+1)]
visited = [0] * (n+1)
cnt = 0
for _ in range(m):
    u, v = map(int, input().split())
    gp[u].append(v)
    gp[v].append(u)

dfs(1)

print(cnt-1)
