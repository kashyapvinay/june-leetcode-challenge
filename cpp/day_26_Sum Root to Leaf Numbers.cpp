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
    void find(TreeNode *root, int curr, int &ans){
        if(root){
            if(!root->left && !root->right){
                ans += curr * 10 + root->val;
                return;
            }
            find(root->left, curr * 10 + root->val, ans);
            find(root->right, curr * 10 + root->val, ans);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        find(root, 0, ans);
        return ans;
    }
};
