class Solution {
public:
    pair<TreeNode*, int> computeLCADepth(TreeNode* root, int level) {
        if (!root) return {nullptr, level};

        auto left = computeLCADepth(root->left, level + 1);
        auto right = computeLCADepth(root->right, level + 1);

        if (left.second == right.second) {
            return {root, left.second};
        }

        return (left.second > right.second) ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return computeLCADepth(root, 0).first;
    }
};
