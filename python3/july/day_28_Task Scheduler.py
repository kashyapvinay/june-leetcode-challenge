class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = [0] * 26
        max_count = 0
        for task in tasks:
            c = int(ord(task) - ord('A'))
            count[c] += 1
            max_count = max(max_count, count[c])
        
        ret = (max_count - 1) * (n + 1)
        for i in range(26):
            if (count[i] == max_count):
                ret += 1

        return max(len(tasks), ret)
