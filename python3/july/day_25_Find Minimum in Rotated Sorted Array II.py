class Solution:
    def findMin(self, nums: List[int]) -> int:
        if(len(nums) <= 0):
            return -1

        n = len(nums)
        l = 0
        r = n - 1
        while(l < r and nums[l] == nums[r]):
            r -= 1

        while(l < r):
            m = l + (r-l)//2
            if (nums[m] > nums[r]):
                l = m + 1
            else:
                r = m

        return nums[l]
