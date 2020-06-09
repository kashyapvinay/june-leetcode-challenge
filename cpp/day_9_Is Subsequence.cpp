class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j, n, m;
        n = s.size();
        m = t.size();
        
        for(i = 0, j = 0; i < m && j < n; i++){
            if(s[j] == t[i]){
                j++;
            }
        }
        return j == n;
    }
};
