n = int(input())
for i in range(n):
    li = list(map(int, input().split()))
    min_val = 101
    res = 0
    for num in li:
        if num % 2 == 0:
            if num < min_val:
                min_val = num
            res += num
    print(res, min_val)