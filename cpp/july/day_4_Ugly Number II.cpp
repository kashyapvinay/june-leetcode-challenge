class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int l2, l3, l5, i, next_2, next_3, next_5;
        l2 = l3 = l5 = 0;
        next_2 = dp[l2] * 2;
        next_3 = dp[l3] * 3;
        next_5 = dp[l5] * 5;
        for(i = 1; i < n; i++){
            dp[i] = min(next_2, min(next_3, next_5));
            if(dp[i] == next_2){
                l2++;
                next_2 = dp[l2] * 2;
            }
            if(dp[i] == next_3){
                l3++;
                next_3 = dp[l3] * 3;
            }
            if(dp[i] == next_5){
                l5++;
                next_5 = dp[l5] * 5;
            }
        }
        return dp[n-1];
    }
};
