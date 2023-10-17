def ffibo(n):
    dp = [0]*(n+4)
    dp[1] = 1
    dp[2] = 1
    dp[3] = 1
    if n<4:
        return dp[n]
    else:
        for i in range(4,n+1):
            dp[i] = dp[i-2]+dp[i-3]
        return dp[n]

T = int(input())
for _ in range(T):
    n = int(input())
    res = ffibo(n)
    print(res)