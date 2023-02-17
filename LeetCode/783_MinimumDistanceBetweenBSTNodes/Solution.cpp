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
    int minimumDifference = INT_MAX;
    TreeNode* prev;
    void dfs(TreeNode* cur){
        if(cur!=NULL){
            dfs(cur->left);
            if(prev!=NULL && minimumDifference > (cur->val)-(prev->val)){
                minimumDifference = (cur->val)-(prev->val);
            }
            prev = cur;
            dfs(cur->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return minimumDifference;
    }
};
