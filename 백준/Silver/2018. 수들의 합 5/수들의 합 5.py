n = int(input())
cnt, ck = 0, 0
start, end = 0, 0

while end <= n:
    if ck < n:
        end += 1
        ck += end
    elif ck > n:
        ck -= start
        start += 1
    else:
        cnt += 1
        end += 1
        ck += end
print(cnt)