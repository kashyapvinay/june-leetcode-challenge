class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res, t;
        ss >> t;
        res = t;
        while(ss >> t){
            res = t + " " + res;
        }
        return res;
    }
};
