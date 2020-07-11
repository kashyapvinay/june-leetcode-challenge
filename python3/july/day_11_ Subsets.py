class Solution:
    def sub(self, nums, pos, t):
        self.res.append(t[::])
        for i in range(pos, len(nums)):
            t.append(nums[i])
            self.sub(nums, i+1, t)
            t.pop()

    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        t = []
        self.sub(nums, 0, t)
        return self.res
    
