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
    void dfs(int dir, int cnt, TreeNode* cur) {
        if(cnt>ret)ret=cnt;
        if(cur->left!=NULL){
            dfs(1, dir==1?1:cnt+1, cur->left);
        }
        if(cur->right!=NULL){
            dfs(2, dir==2?1:cnt+1, cur->right);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(0,0,root);
        return ret;
    }
};
