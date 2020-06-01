# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def invert(root):
            if root is not None:
                left = root.left
                right = root.right
                
                root.left = right
                root.right = left
                
                invert(left)
                invert(right)

        invert(root)
        return root
