# BOJ_7576 : 토마토마토
import sys
from collections import deque


input = sys.stdin.readline


def bfs(pos1):
    q = deque()
    res = 0
    while pos1:
        x, y = pos1.pop()
        q.append([x, y])
    while q:
        i, j = q.popleft()
        res = tomatoes[i][j]
        for di, dj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            ni, nj = i + di, j + dj
            if 0 <= ni < n and 0 <= nj < m and tomatoes[ni][nj] == 0 and tomatoes[ni][nj] != -1:
                q.append([ni, nj])
                tomatoes[ni][nj] = tomatoes[i][j] + 1
    return res


def find_tomato():
    res = []
    for x in range(n):
        for y in range(m):
            if tomatoes[x][y] == 1:
                res.append([x, y])
    return res


def find_zero(pos1):
    for x in range(n):
        for y in range(m):
            if tomatoes[x][y] == 0:
                return -1
    return pos1


m, n = map(int, input().split())
tomatoes = [list(map(int, input().rstrip().split())) for _ in range(n)]

start_points = find_tomato()
date = bfs(start_points)
ans = find_zero(date - 1)
print(ans)
