# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, root, level):
        if(root):
            if(level == self.max_level and len(self.res) == level):
                self.res.append([])
                self.max_level += 1
            
            self.res[level].append(root.val)

            self.traverse(root.left, level+1)
            self.traverse(root.right, level+1)
    
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        self.res = []
        if(not root):
            return self.res
        
        self.max_level = 0
        self.traverse(root, 0)
        for i in range(1, len(self.res), 2):
            self.res[i] = self.res[i][::-1]

        return self.res
