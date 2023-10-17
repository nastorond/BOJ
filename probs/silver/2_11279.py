import sys, heapq
from collections import deque
input = sys.stdin.readline
li = []
res = deque()
cnt = 0
n = int(input())
for _ in range(n):
    x = int(input())
    if x:
        heapq.heappush(li, -x)
    else:
        cnt += 1
        if len(li):
            s = heapq.heappop(li)
            res.append(-s)
        else:
            res.append(0)
for i in range(cnt):
    print(res.popleft())