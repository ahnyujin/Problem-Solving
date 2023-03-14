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
    int ret = 0;
    void dfs(TreeNode* cur, int sum) {
        if(cur == nullptr){
            return;
        }
        if( cur->left==nullptr && cur->right == nullptr) {
            ret+=(sum*10 + (cur->val));
            return;
        }
        dfs(cur->left, sum*10+(cur->val));
        dfs(cur->right, sum*10+(cur->val));
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};
