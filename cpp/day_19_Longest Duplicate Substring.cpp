class Solution {
public:
    bool check_old(string s, int k, string &res){
        unordered_set<string> hash;
        for(int i = 0; i < s.size() - k + 1; i++){
            string t = s.substr(i, k);
            if(hash.find(t) != hash.end()){
                if(res.size() < t.size()){
                    res = t;
                }
                return true;
            }
            hash.insert(t);
        }
        return false;
    }
    
    bool check(string s, int k, string &res){
        unordered_map<unsigned long long, int> mp;
        unsigned long long p = 29;
        unsigned long long h = 1;
        unsigned long long curr_hash = 0;
        int i;

        for(i = 0; i < k; i++){
            curr_hash = curr_hash * p + (s[i] - 'a');
            h = h * p;
        }
        
        mp[curr_hash] = 0;
        
        for(i = k; i < s.size(); i++){
            curr_hash = curr_hash * p + (s[i] - 'a');
            curr_hash = curr_hash - h * (s[i - k] - 'a');
            if(mp.find(curr_hash) != mp.end()){
                int idx = mp[curr_hash];
                string t1 = s.substr(idx, k);
                string t2 = s.substr(i-k+1, k);
                if(t1 == t2){
                    if(t1.size() > res.size()){
                        res = t1;
                    }
                    return true;
                }
            }
            mp[curr_hash] = i-k+1;
        }
        
        return false;
    }
    
    string longestDupSubstring(string S) {
        int left=0, mid, n = S.size(), right = S.size() -1;
        string res = "";
        while(left <= right){
            mid = left + (right-left)/2;
            if(check(S, mid, res)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};
