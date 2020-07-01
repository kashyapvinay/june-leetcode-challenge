class Solution {
public:

    int numTrees(int n) {
        int i, j;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= i; j++){
                dp[i] = dp[i] + (dp[i-j] * dp[j-1]);
            }
        }
        return dp[n];
    }
};
