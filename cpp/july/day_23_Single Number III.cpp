class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_xor_y = 0, x = 0, y = 0, i, diff;
        for(i = 0; i < nums.size(); i++){
            x_xor_y ^= nums[i];
        }
        diff = (x_xor_y & (x_xor_y - 1)) ^ x_xor_y;
        
        for(i = 0; i < nums.size(); i++){
            if(nums[i] & diff){
                x ^= nums[i];
            }else{
                y ^= nums[i];
            }
        }
        return vector<int>{x, y};
    }
};
