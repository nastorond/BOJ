import sys
from collections import deque
import heapq
input = sys.stdin.readline


def dijkstra():
    q = []
    heapq.heappush(q, (fld[0][0], 0, 0))
    visited[0][0] = fld[0][0]
    while q:
        weight, x, y = heapq.heappop(q)
        if visited[x][y] < weight:
            continue
        for dx, dy in [[0, 1],[1, 0],[0, -1],[-1, 0]]:
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] == 1e6:
                cost = weight + fld[nx][ny]
                if cost < visited[nx][ny]:
                    visited[nx][ny] = cost
                    heapq.heappush(q, (cost, nx, ny))


tc = 0
while 1:
    n = int(input())
    if n == 0:
        break
    tc += 1
    visited = [[1e6]*n for _ in range(n)]
    fld = [list(map(int, input().split())) for _ in range(n)]

    dijkstra()

    res = visited[n-1][n-1]

    print(f'Problem {tc}: {res}')