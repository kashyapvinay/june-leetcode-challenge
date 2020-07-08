class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, value, t;
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(i = 0; i < nums.size() - 2; i++){
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                j = i+1;
                k = nums.size()-1;
                value = 0 - nums[i];
                while(j < k){
                    t = nums[j] + nums[k];
                    if(t == value){
                        res.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j+1]){
                            j++;
                        }
                        while(j < k && nums[k-1] == nums[k]){
                            k--;
                        }
                        j++;
                        k--;
                    }else if(t > value){
                        k--;
                    }else{
                        j++;
                    }
                }
            }
        }
        return res;
    }
};
