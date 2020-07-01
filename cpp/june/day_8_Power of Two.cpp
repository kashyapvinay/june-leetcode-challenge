class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0){
            return 0;
        }
        int count = 0;
        while(n){
            n = n & (n-1);
            count++;
        }
        return count == 1;
    }
};
