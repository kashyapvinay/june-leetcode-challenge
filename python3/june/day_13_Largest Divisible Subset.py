class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n <= 1:
            return nums
        nums.sort()
        dp = [1] * n
        path = [-1] * n
        ans = 0
        for i in range(1, n):
            for j in range(0, i):
                if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    path[i] = j
            if dp[i] > dp[ans]:
                ans = i
        
        res = []
        while ans >= 0:
            res.append(nums[ans])
            ans = path[ans]
        res.reverse()
        return res
