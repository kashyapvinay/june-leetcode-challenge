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
    int widthOfBinaryTree(TreeNode* root) {
        int i;
        unsigned long left = 0, right = 0, s, ans = 0;
        queue<pair<TreeNode*, unsigned long>> q;
        q.push({root, 0});
        while(!q.empty()){
            s = q.size();
            left = right = 0;
            for(i = 0; i < s; i++){
                auto t = q.front();
                q.pop();
                if(i == 0){
                    left = t.second;
                }
                if(i == s - 1){
                    right = t.second;
                }
                if(t.first->left){
                    q.push({t.first->left, 2 * t.second});
                }
                if(t.first->right){
                    q.push({t.first->right, 2 * t.second + 1});
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
