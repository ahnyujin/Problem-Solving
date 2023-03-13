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
    bool compareTree(TreeNode* x, TreeNode* y){
        if((x==nullptr && y==nullptr)){
            return true;
        }
        if(x==nullptr || y==nullptr){
            return false;
        }
        return x->val == y->val && compareTree(x->left,y->right) && compareTree(x->right,y->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return compareTree(root->left, root->right);
    }
};
