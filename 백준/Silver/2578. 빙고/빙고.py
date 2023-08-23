import sys
input = sys.stdin.readline


def find_num(pos1):
    for x in range(5):
        for y in range(5):
            if bingo[x][y] == pos1:
                ck[x][y] = 1
                return


def ck_bingo(pos1):
    cnt3 = 0
    cnt4 = 0
    for x in range(5):
        cnt1 = 0
        cnt2 = 0
        for y in range(5):
            cnt1 += ck[x][y]
            cnt2 += ck[y][x]
            if x + y == 4:
                cnt4 += ck[x][y]

        cnt3 += ck[x][x]

        if cnt1 == 5:
            pos1 += 1
        if cnt2 == 5:
            pos1 += 1
    
    if cnt3 == 5:
        pos1 += 1
    if cnt4 == 5:
        pos1 += 1
    
    return pos1



bingo = [list(map(int, input().split())) for _ in range(5)]
ck = [[0] * 5 for _ in range(5)]

orders = []
for _ in range(5):
    command = list(map(int, input().split()))
    orders.extend(command)

for idx in range(25):
    find_num(orders[idx])
    if idx > 9:
        bingo_cnt = ck_bingo(0)
        if bingo_cnt >= 3:
            break

print(idx + 1)