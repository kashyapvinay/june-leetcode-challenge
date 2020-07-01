class Solution:
    def arrangeCoins(self, n: int) -> int:
        l = 0
        h = n
        while(l <= h):
            mid = l + (h - l)//2
            curr = (mid * (mid+1))//2
            if(curr <= n):
                ans = mid
                l = mid + 1
            else:
                h = mid - 1

        return ans
