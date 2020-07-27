# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def build(self, inorder, postorder, l, r):
        if(l > r):
            return None

        idx = 0
        while(inorder[idx] != postorder[self.post_idx]):
            idx += 1
        
        root = TreeNode(postorder[self.post_idx])
        self.post_idx -= 1
        if(l == r):
            return root

        root.right = self.build(inorder, postorder, idx+1, r)
        root.left = self.build(inorder, postorder, l, idx-1)
        
        return root

    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if len(postorder) == 0:
            return None
        
        self.post_idx = len(postorder) - 1
        return self.build(inorder, postorder, 0, len(inorder) - 1)
