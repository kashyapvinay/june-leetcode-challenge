class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        if(len(nums) < 3):
            return res

        nums.sort()
        for i in range(len(nums) - 2):
            if (i == 0 or (i > 0 and nums[i] != nums[i-1])):
                j = i + 1
                k = len(nums) - 1
                value = 0 - nums[i]
                while(j < k):
                    t = nums[j] + nums[k]
                    if(t == value):
                        res.append([nums[i], nums[j], nums[k]])
                        while(j < k and nums[j] == nums[j+1]):
                            j += 1

                        while(j < k and nums[k-1] == nums[k]):
                            k -= 1

                        j += 1
                        k -= 1
                    elif(t > value):
                        k -= 1
                    else:
                        j += 1

        return res
