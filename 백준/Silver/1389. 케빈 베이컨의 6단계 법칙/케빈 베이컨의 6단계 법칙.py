# BOJ_1389 : 케빈 베이컨의 6단계 법칙
import sys
from collections import deque

input = sys.stdin.readline


def find_kevin_num(pos1):
    visited = [0] * (n+1)
    q = deque()
    q.append(pos1)
    visited[pos1] = 1
    while q:
        num = q.popleft()
        for con in friends_map[num]:
            if not visited[con]:
                visited[con] = visited[num] + 1
                q.append(con)
    visited = list(map(lambda x: x-1, visited))
    return sum(visited[1:])


n, m = map(int, input().rstrip().split())
friends_map = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().rstrip().split())
    friends_map[u].append(v)
    friends_map[v].append(u)

res = []
for i in range(1, n+1):
    how_connect = find_kevin_num(i)
    res.append([how_connect, i])

res.sort(key=lambda x: (x[0], x[1]))

print(res[0][1])
