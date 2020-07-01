class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i, j, n, ans = 0;
        n = nums.size();
        if(n < 1){
            return {};
        }
        vector<int> dp(n, 1), path(n, -1), res;
        sort(nums.begin(), nums.end());
        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
            if(dp[ans] < dp[i]){
                ans = i;
            }
        }
        j = ans;
        while(j >= 0){
            res.push_back(nums[j]);
            j = path[j];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
