import sys

input = sys.stdin.readline

n = int(input())
students = list(map(int, input().split()))

dp = [0] * (n + 1)

for i in range(1, n + 1):
    if i == 1:
        dp[i] = 0
    elif i == 2:
        dp[i] = abs(students[i - 1] - students[i - 2])
    else:
        candidates = []
        for j in range(i - 1, -1, -1):
            s = max(students[j:i]) - min(students[j:i]) + dp[j]
            candidates.append(s)
        dp[i] = max(candidates)

print(dp[n])