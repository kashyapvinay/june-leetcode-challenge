class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() <= 0){
            return -1;
        }

        int n = nums.size(), l = 0, r = n - 1, m;
        while(l < r && nums[l] == nums[r]){
            r -= 1;
        }
        while(l < r){
            m = l + (r-l)/2;
            if (nums[m] > nums[r]){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return nums[l];
    }
};
