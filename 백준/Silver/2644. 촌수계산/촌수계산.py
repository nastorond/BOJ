import sys
from collections import deque
input = sys.stdin.readline


def find_num(start_point, end_point):
    q = deque()
    q.append(start_point)
    visited[start_point] = 1
    while q:
        ppl_num = q.popleft()
        if ppl_num == end_point:
            return visited[ppl_num] - 1

        for i in gp[ppl_num]:
            if not visited[i]:
                visited[i] = visited[ppl_num] + 1
                q.append(i)
    return -1


n = int(input())
start_node, end_node = map(int, input().split())
gp = [[] for _ in range(n+1)]
visited = [0] * (n+1)
e = int(input())
for _ in range(e):
    par, chd = map(int, input().split())
    gp[par].append(chd)
    gp[chd].append(par)

res = find_num(start_node, end_node)
print(res)