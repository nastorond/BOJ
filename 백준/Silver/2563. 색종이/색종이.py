import sys
input = sys.stdin.readline
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

fld = [[0 for _ in range(100)] for _ in range(100)]

res = 0
for i in arr:
    x,y = i[0],i[1]

    for u in range(x, x+10):
        for v in range(y,y+10):
            fld[u][v] = 1

for i in fld:
    res += sum(i)

print(res)