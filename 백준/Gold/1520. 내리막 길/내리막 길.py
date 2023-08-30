# boj 1520 : 내리막 길
import sys

input = sys.stdin.readline


def find_route(x, y):
    if x == m-1 and y == n-1:
        return 1

    if visited[x][y] != -1:
        return visited[x][y]
    
    visited[x][y] = 0

    for di, dj in [[0,1],[1,0],[0,-1],[-1,0]]: 
        ni, nj = di + x, dj + y
        if 0<=ni<m and 0<=nj<n and fld[ni][nj] < fld[x][y]:
            visited[x][y] += find_route(ni, nj)
    
    return visited[x][y]


m, n = map(int, input().split())
fld = [list(map(int, input().split())) for _ in range(m)]
visited = [[-1]*n for _ in range(m)]
res = find_route(0, 0)
print(res)
