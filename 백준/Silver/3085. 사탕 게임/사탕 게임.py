import sys

input = sys.stdin.readline

n = int(input())

candies = [list(input().rstrip()) for _ in range(n)]


def func(x, y, u, v):
    cnt1, cnt2 = 1, 1
    f_cnt = []
    candies[x][y], candies[u][v] = candies[u][v], candies[x][y]
    for add_idx in range(1, n):
        if candies[add_idx - 1][y] == candies[add_idx][y]:
            cnt1 += 1
        else:
            f_cnt.append(cnt1)
            cnt1 = 1
        if candies[x][add_idx - 1] == candies[x][add_idx]:
            cnt2 += 1
        else:
            f_cnt.append(cnt2)
            cnt2 = 1
        f_cnt.append(cnt1)
        f_cnt.append(cnt2)

    candies[x][y], candies[u][v] = candies[u][v], candies[x][y]

    return max(f_cnt)


counts = []
for i in range(n):
    for j in range(n):
        for mi, mj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            di, dj = mi + i, mj + j
            if 0 <= di < n and 0 <= dj < n:
                counts.append(func(i, j, di, dj))
print(max(counts))