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
    vector<int> ret;
    void recursive(TreeNode* node) {
        if(node!=NULL){
            recursive(node->left);
            ret.push_back(node->val);
            recursive(node->right);
        }
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        recursive(root);
        return ret;
    }
};
