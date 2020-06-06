import random

class Solution:

    def __init__(self, w: List[int]):
        self.m = []
        s = 0
        for d in w:
            s += d
            self.m.append(s)

    def pickIndex(self) -> int:
        n = random.randint(1, self.m[-1])
        return bisect.bisect_left(self.m, n)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
