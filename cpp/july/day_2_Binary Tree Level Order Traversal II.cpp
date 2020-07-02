/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *root, int level, int& max_level, vector<vector<int>>& res){
        if(root){
            max_level = max(level, max_level);
            if(max_level == res.size()){
                res.push_back(vector<int>());
            }
            res[level].push_back(root->val);
            traverse(root->left, level+1, max_level, res);
            traverse(root->right, level+1, max_level, res);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        int max_level = 0;
        traverse(root, 0, max_level, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
