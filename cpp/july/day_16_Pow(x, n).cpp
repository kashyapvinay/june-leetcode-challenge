class Solution {
public:
    double calculate(double x, long n){
        if(n == 0 || x == 1){
            return 1.0;
        }
        double res = 1.0;
        res = res * calculate(x, n/2);
        res = res * res;
        if(n % 2 == 1){
            res = res * x;
        }
        return res;
    }
    
    double myPow(double x, int n_n) {
        long n = n_n;
        if(n < 0){
            x = 1.0 / x;
            n = -n;
        }
        int sign = 1;
        if(x < 0 && n % 2){
            sign = -1;
            x = -x;
        }
        double ans = calculate(x, n);
        return ans * sign;
    }
};
