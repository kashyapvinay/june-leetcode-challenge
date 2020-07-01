# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find(self, root, curr):
        if(root is not None):
            if(not root.left and not root.right):
                self.ans += curr * 10 + root.val
                return
            self.find(root.left, curr * 10 + root.val)
            self.find(root.right, curr * 10 + root.val)

    def sumNumbers(self, root: TreeNode) -> int:
        self.ans = 0
        self.find(root, 0)
        return self.ans
