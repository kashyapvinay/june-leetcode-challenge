class Solution {
public:
    int find(vector<vector<int>> &memo, int amount, int m, vector<int> &coins){
        if(amount == 0){
            return 1;
        }
        if(amount < 0 || (m < 0 && amount >= 1)){
            return 0;
        }
        if(memo[m][amount] != -1){
            return memo[m][amount];
        }
        // cout << amount << " " << m << endl;
        memo[m][amount] = find(memo, amount, m-1, coins) + find(memo, amount-coins[m], m, coins);
        return memo[m][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        return find(memo, amount, coins.size()-1, coins);
    }
};
