class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(filter(lambda x: x.strip(), reversed(s.strip().split(" "))))
