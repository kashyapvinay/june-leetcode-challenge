class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 0:
            return False
        count = 0
        while(n):
            n = n & (n-1)
            count += 1
        return count == 1
