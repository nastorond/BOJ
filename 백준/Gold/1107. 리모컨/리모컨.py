import sys

input = sys.stdin.readline
Num = int(input().rstrip())
N = int(input())
if N:
    li = list(input().split())
else:
    li = []

base_val = abs(Num - 100)
mn_mx, mn_mn = 1e6, 1e6

if int(Num) == 100:
    print(0)
else:
    for i in range(Num, 500000 * 2):
        for j in str(i):
            if j in li:
                break
        else:
            mn_mx = i
            break

    for i in range(Num, -1, -1):
        for j in str(i):
            if j in li:
                break
        else:
            mn_mn = i
            break

    res_mn = abs(Num - mn_mn) + len(str(mn_mn))
    res_mx = abs(Num - mn_mx) + len(str(mn_mx))

    print(min(res_mn, res_mx, base_val))
