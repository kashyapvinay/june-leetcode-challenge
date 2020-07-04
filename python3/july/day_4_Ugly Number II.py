class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1] * n
        l2 = l3 = l5 = 0
        next_2 = dp[l2] * 2
        next_3 = dp[l3] * 3
        next_5 = dp[l5] * 5
        for i in range(1, n):
            dp[i] = min(next_2, min(next_3, next_5))
            if(dp[i] == next_2):
                l2 += 1
                next_2 = dp[l2] * 2

            if(dp[i] == next_3):
                l3 += 1
                next_3 = dp[l3] * 3

            if(dp[i] == next_5):
                l5 += 1
                next_5 = dp[l5] * 5

        return dp[n-1]
