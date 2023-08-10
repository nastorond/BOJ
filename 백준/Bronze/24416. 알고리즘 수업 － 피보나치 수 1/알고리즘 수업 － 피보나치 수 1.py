def fibo(n):
    dp = [0]*(n+1)
    dp[0],dp[1],dp[2] = 0, 1, 1
    for i in range(3,n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

n = int(input())
ans1 = fibo(n)
print(ans1, n-2)