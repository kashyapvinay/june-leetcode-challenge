class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [key for key, v in Counter(nums).most_common(k)]
