import sys, heapq
input = sys.stdin.readline
n = int(input())
li = []
for _ in range(n): heapq.heappush(li, int(input()))
res=0
while len(li)>1:
    s = heapq.heappop(li)
    v = heapq.heappop(li)
    sav = s+v
    res += sav
    heapq.heappush(li, sav)
print(res)