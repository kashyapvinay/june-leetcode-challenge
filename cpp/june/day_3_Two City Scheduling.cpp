class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int i, ans=0, n=costs.size();
        sort(costs.begin(), costs.end(), [&](vector<int> &c1, vector<int> &c2){
            return (c1[0] - c1[1]) < (c2[0] - c2[1]);
        });
        for(i = 0; i < n/2; i++){
            ans += costs[i][0] + costs[i+n/2][1];
        }
        return ans;
    }
};
