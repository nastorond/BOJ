# BOJ_16173 : 점프왕 쩰리(Small)
import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def ck_avail(x, y):
    global flg

    dis = fld[x][y]
    if x == size - 1 and y == size - 1:
        flg = True
        return

    if dis == 0:
        return

    for di, dj in [[0, 1], [1, 0]]:
        ni, nj = di * dis + x, dj * dis + y
        if 0 <= ni < size and 0 <= nj < size:
            ck_avail(ni, nj)


size = int(input())
fld = [list(map(int, input().rstrip().split())) for _ in range(size)]
flg = False
ck_avail(0, 0)
if flg:
    print('HaruHaru')
else:
    print('Hing')
