# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, root, level):
        if(root):
            self.max_level = max(level, self.max_level)
            if(self.max_level == len(self.res)):
                self.res.append([])

            self.res[level].append(root.val)
            self.traverse(root.left, level+1)
            self.traverse(root.right, level+1)
            
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        self.res = []
        self.max_level = 0
        self.traverse(root, 0)
        self.res.reverse()
        return self.res
