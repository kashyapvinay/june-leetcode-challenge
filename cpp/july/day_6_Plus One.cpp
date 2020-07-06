class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, s, c = 1;
        for(i = digits.size() - 1; i >= 0 && c; i--){
            s = digits[i] + c;
            c = s / 10;
            digits[i] = s % 10;
        }
        if(c){
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};
