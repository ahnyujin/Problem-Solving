class Solution {
public:
    int union_find(vector<int>& parent, int x){
        if(parent[x]==x) return x;
        return parent[x] = union_find(parent, parent[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1); 
        for(int i=1;i<=n;i++) {
            parent[i]=i;
        }

        for (auto& edge:edges) {
            int a = edge[0];
            int b = edge[1];
            int parent_a = union_find(parent, a);
            int parent_b = union_find(parent, b);
            if (parent_a == parent_b) return edge;
            parent[parent_a] = parent_b;
        }
        return {};
    }
};
