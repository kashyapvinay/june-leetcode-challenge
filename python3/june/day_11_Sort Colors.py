class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = -1
        right = len(nums)
        i = 0
        while i < right:
            if left + 1 < right and nums[left+1] == 0:
                left += 1
                i += 1
                continue
            
            if right - 1 > left and nums[right-1] == 2:
                right -= 1
                continue

            
            if nums[i] == 0:
                left += 1
                nums[left], nums[i] = nums[i], nums[left]
            elif nums[i] == 2:
                right -= 1
                nums[right], nums[i] = nums[i], nums[right]
            else:
                i += 1
