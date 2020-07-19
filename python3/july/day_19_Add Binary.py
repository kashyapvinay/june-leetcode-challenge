class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        i = 0
        a = a[::-1]
        b = b[::-1]
        c = 0
        while(i < len(a) or i < len(b)):
            s = c
            if(i < len(a)):
                s += 1 if a[i] == '1' else 0

            if(i < len(b)):
                s += 1 if b[i] == '1' else 0

            c = s // 2
            s = s % 2
            res += '1' if s else '0'
            i += 1

        if(c):
            res += '1'

        return res[::-1]
