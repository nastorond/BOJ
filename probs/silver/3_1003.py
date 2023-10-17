def fibo(n):
    dp = [0]*(n+1)
    if n == 1: return 1
    if n == 0: return 0
    else:
        dp[0], dp[1] = 0, 1
        for i in range(2, n+1):
            dp[i] = dp[i-2] + dp[i-1]
        return dp[n]

def fibo_0(n):
    dp = [0]*(n+1)
    if n == 1: return 0
    if n == 0: return 1
    else:
        n = n-1
        dp[0], dp[1] = 0, 1
        for i in range(2, n+1):
            dp[i] = dp[i-2] + dp[i-1]
        return dp[n]

n = int(input())
for _ in range(n):
    num = int(input())
    cnt_0 = fibo_0(num)
    cnt_1 = fibo(num)
    print(cnt_0, cnt_1)