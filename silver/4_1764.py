import sys
input = sys.stdin.readline
nam = {}
n,m = map(int, input().split())
for i in range(n):
    nam[input().rstrip()] = 1
for i in range(m):
    nn = input().rstrip()
    if nn in nam:
        nam[nn] += 1
cnt = 0
res = []
for k,v in nam.items():
    if v == 2:
        cnt += 1
        res.append(k)
res.sort()
print(cnt)
for i in res:
    print(i)