# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        ans = 0
        q = collections.deque([(root, 0)])
        while(len(q)):
            s = len(q)
            left = right = 0
            for i in range(s):
                t = q.popleft()
                if(i == 0):
                    left = t[1]

                if(i == s - 1):
                    right = t[1]

                if(t[0].left):
                    q.append((t[0].left, 2 * t[1]))

                if(t[0].right):
                    q.append((t[0].right, 2 * t[1] + 1))
                
            
            ans = max(ans, right - left + 1)

        return ans
