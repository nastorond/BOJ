import sys
from collections import deque
input = sys.stdin.readline
def find_island(x, y):
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    while q:
        dx, dy = q.popleft()

        for di, dj in [[0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1]]:
            ni, nj = dx + di, dy + dj

            if 0 <= ni < h and 0 <= nj < w and not visited[ni][nj] and fld[ni][nj]:
                visited[ni][nj] = 1
                q.append([ni, nj])
    return 1


tc = 0
while 1:
    tc += 1
    w, h = map(int, input().split())
    res = 0

    if w == 0 and h == 0:
        break

    if w == 1:
        fld = [[int(input())] for _ in range(h)]
        visited = [[0] for _ in range(h)]
    else:
        fld = [list(map(int, input().split())) for _ in range(h)]
        visited = [[0] * w for _ in range(h)]

    for i in range(h):
        for j in range(w):
            if fld[i][j] and not visited[i][j]:
                res += find_island(i, j)

    print(res)