import sys

input = sys.stdin.readline

row, col = map(int, input().split())
n = int(input())
stores = [list(map(int, input().split())) for _ in range(n)]
now_loc = list(map(int, input().split()))

res = 0
for x, y in stores:
    if x == now_loc[0]:
        res += abs(now_loc[1] - y)

    else:
        if x + now_loc[0] == 3 or x + now_loc[0] == 7:
            sav1 = y + now_loc[1]
            sav2 = (row - y) + (row - now_loc[1])
            res += min(sav1, sav2)

            if x == 1 or x == 2:
                res += col
            else:
                res += row

        elif now_loc[0] == 1:
            if x == 3:
                res += y + now_loc[1]
            elif x == 4:
                res += y + (row - now_loc[1])

        elif now_loc[0] == 2:
            if x == 3:
                res += (col - y) + now_loc[1]
            elif x == 4:
                res += (col - y) + (row - now_loc[1])

        elif now_loc[0] == 3:
            if x == 1:
                res += y + now_loc[1]
            elif x == 2:
                res += (col - y) + now_loc[1]

        elif now_loc[0] == 4:
            if x == 2:
                res += row - y + (col - now_loc[1])
            elif x == 1:
                res += row - y + now_loc[1]

print(res)