class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        c = 1
        for i in range(len(digits)-1, -1, -1):
            s = digits[i] + c
            c = s // 10
            digits[i] = s % 10
            if c == 0:
                break
        if(c):
            digits.insert(0, c)

        return digits
