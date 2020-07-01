class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> levels, nums(n+1);
        string res = "";
        int i, j;
        k--;
        for(i = 2; i <= n; i++){
            levels.push_back(k%i);
            k = k / i;
        }
        levels.push_back(0);
        reverse(levels.begin(), levels.end());
        
        for(i = 0; i < n; i++){
            nums[i] = i+1;
        }

        for(i = 1; i < n; i++){
            j = levels[i];
            res += to_string(nums[j]);
            nums.erase(nums.begin() + j);
        }
        res += to_string(nums[0]);
        return res;
        
    }
};
