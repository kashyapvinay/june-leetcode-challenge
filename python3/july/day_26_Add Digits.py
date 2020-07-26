class Solution:
    def addDigits(self, num: int) -> int:
        return num - 9 * int((num -1)//9) if num else 0
