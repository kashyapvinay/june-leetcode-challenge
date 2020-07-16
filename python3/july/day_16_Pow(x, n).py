class Solution:
    def myPow(self, x: float, n: int) -> float:

        def calculate(x, n):
            if(n == 0 or x == 1):
                return 1.0

            res = 1.0
            res = res * calculate(x, n//2)
            res = res * res
            if(n % 2 == 1):
                res = res * x

            return res
    
        if(n < 0):
            x = 1.0 / x
            n = -n

        sign = 1
        if(x < 0 and n % 2):
            sign = -1
            x = -x

        return calculate(x, n) * sign
