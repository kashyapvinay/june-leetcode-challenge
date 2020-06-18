class Solution:
    def hIndex(self, citations: List[int]) -> int:
        N, left, right = len(citations), 0, len(citations)-1
        while left <= right:
            mid = left + (right - left)//2
            if citations[mid] == N - mid:
                return citations[mid]
            elif citations[mid] > N - mid:
                right = mid - 1
            else:
                left = mid + 1
        return N - left
