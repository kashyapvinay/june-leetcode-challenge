class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n+1):
            for j in range(0, int(i ** .5)+1):
                dp[i] = min(dp[i], 1 + dp[i - j*j])
        return dp[n]
