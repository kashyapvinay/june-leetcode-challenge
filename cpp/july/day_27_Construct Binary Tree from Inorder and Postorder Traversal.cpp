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
    TreeNode* build(vector<int>& in, vector<int>& post, int l, int r, int& post_idx){
        if(l > r){
            return NULL;
        }
        int idx = 0;
        while(in[idx] != post[post_idx]){
            idx++;
        }
        TreeNode* root = new TreeNode(post[post_idx--]);
        if(l == r){
            return root;
        }
        root->right = build(in, post, idx+1, r, post_idx);
        root->left = build(in, post, l, idx-1, post_idx);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0){
            return NULL;
        }
        int post_idx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, post_idx);
    }
};
