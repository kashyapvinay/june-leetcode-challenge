class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left, right, i;
        left = -1;
        right = nums.size();
        i = 0;
        while(i < right){
            if(left+1 < right && nums[left+1] == 0){
                left++;
                i++;
                continue;
            }
            if(right > 1 && nums[right-1] == 2){
                right--;
                continue;
            }
            if(nums[i] == 0){
                left++;
                swap(nums[i], nums[left]);
            }else if(nums[i] == 2){
                right--;
                swap(nums[i], nums[right]);
            }else{
                i++;
            }
        }
    }
};
