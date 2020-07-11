class Solution {
public:
    void sub(vector<vector<int>> &res, vector<int> &nums, int pos, vector<int> &t){
        res.push_back(t);
        for(int i = pos; i < nums.size(); i++){
            t.push_back(nums[i]);
            
            sub(res, nums, i+1, t);
            t.pop_back();   
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        sub(res, nums, 0, t);
        return res;
    }
};
