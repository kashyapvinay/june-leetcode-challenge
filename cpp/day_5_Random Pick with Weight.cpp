class Solution {
    vector<int> m;
    random_device rd;
public:
    Solution(vector<int> w) {
        int sum = 0;
        for (int i = 0; i < w.size(); ++i){
            sum += w[i];
            m.push_back(sum);
        }
    }
    int pickIndex() {
        return lower_bound(m.begin(), m.end(), rd() % m.back() + 1) - m.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
