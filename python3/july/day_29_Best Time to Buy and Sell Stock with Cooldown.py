class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if(len(prices) <= 1):
            return 0
        s0 = [0] * len(prices)
        s1 = [0] * len(prices)
        s2 = [0] * len(prices)
        s0[0] = 0
        s1[0] = -prices[0]
        s2[0] = float('-inf')
        for i in range(1, len(prices)):
            s0[i] = max(s0[i-1], s2[i-1])
            s1[i] = max(s0[i-1] - prices[i], s1[i-1])
            s2[i] = s1[i-1] + prices[i]

        return max(s2[len(prices) - 1], s0[len(prices) -1 ])
