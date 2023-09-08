nums = []
for _ in range(7):
    n = int(input())
    if n%2:
        nums.append(n)
if nums:
    print(sum(nums))
    print(min(nums))
else:
    print(-1)