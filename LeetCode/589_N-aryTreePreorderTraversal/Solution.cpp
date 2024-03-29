/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ret;
    void dfs(Node* cur) {
        ret.push_back(cur->val);
        for(Node* next : cur->children){
            dfs(next);
        }
    }
    vector<int> preorder(Node* root) {
        if(root == NULL) return ret;
        dfs(root);
        return ret;
    }
};
