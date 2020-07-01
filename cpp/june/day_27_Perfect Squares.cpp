class Solution {
public:
    vector<int> dp;

    int recur_1(int n){
        if(n == 0){
            return 0;
        }
        if(n < 0){
            return INT_MAX-1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        int i, res = INT_MAX;
        for(i = 1; i*i <= n; i++){
            res = min(res, 1 + recur_1(n - i*i));
        }
        dp[n] = res;
        return dp[n];
    }
    
    int numSquares(int n) {
        dp = vector<int>(n+1, -1);
        return recur_1(n);
    }
};
