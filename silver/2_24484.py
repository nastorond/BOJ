def dfs(gp, v, visited):
    global res
    visited[v] = True
    res.append(v)
    for i in gp[v]:
        print(i)
        if not visited[i]:
            dfs(gp,i,visited)


res = []
n, m, r = map(int, input().split())
gp  = [[] for _ in range(n+1)]
visited = [False]*(n+1)

for _ in range(m):
    u,v = map(int,input().split())
    gp[u].append(v)
    gp[v].append(u)

for i in range(n):gp[i].sort(reverse=True)

dfs(gp,r,visited)

# if len(res) != (n+1):
#     li = [0 for _ in range(n-len(res))]
#     res.extend(li)

# print(res)
