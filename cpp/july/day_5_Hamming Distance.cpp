class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, count = 0;
        while(z){
            z = z &(z-1);
            count++;
        }
        return count;
    }
};
