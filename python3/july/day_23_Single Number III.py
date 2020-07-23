class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        x_xor_y, x, y = 0, 0, 0
        for i in range(len(nums)):
            x_xor_y ^= nums[i]
        
        diff = (x_xor_y & (x_xor_y - 1)) ^ x_xor_y
        
        for i in range(len(nums)):
            if(nums[i] & diff):
                x ^= nums[i]
            else:
                y ^= nums[i]

        return [x, y]
