def solution(m, n, puddles) -> int:
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for li in puddles:
        dp[li[1]][li[0]] = -1
    
    dp[1][1] = 1
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if dp[i][j] == -1:
                dp[i][j] = 0
                continue
            if dp[i-1][j] != -1:
                dp[i][j] += dp[i-1][j]
            if dp[i][j-1] != -1:
                dp[i][j] += dp[i][j-1]
            dp[i][j] %= 1000000007
    
    return dp[n][m]
