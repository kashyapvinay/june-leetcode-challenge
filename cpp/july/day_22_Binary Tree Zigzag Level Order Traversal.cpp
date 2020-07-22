/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *root, vector<vector<int>> &res, int level, int &max_level){
        if(root){
            if(level == max_level && res.size() == level){
                res.push_back(vector<int>());
                max_level++;   
            }
            res[level].push_back(root->val);
            
            traverse(root->left, res, level+1, max_level);
            traverse(root->right, res, level+1, max_level);
        }
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        int max_level = 0, i;
        traverse(root, res, 0, max_level);
        for(i = 1; i < res.size(); i+=2){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
