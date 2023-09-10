nums = list(range(1, 21))
for _ in range(10):
    a, b = map(int, input().split())
    rev_lis = (nums[a-1:b])[::-1]
    cnt = 0
    for i in range(a-1, b):
        nums[i] = rev_lis[cnt]
        cnt += 1
print(*nums)
