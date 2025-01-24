class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<vector<int>> adj;
        vector<int> ret;
        adj.resize(size, vector<int>(0));
        
        vector<int> table = vector<int>(size,0);
        queue<int> q;
        for (int i=0; i<size; i++){
            for (int v:graph[i]){
                adj[v].push_back(i);
                table[i]++;
            }

            if (table[i]==0){
                q.push(i);
            }
        }

        while (q.size()){
            int cur_x=q.front();
            ret.push_back(cur_x);
            q.pop();
            for (auto x:adj[cur_x]){
                table[x]--;
                if (table[x]==0){
                    q.push(x);
                }
            }
        }

        sort(ret.begin(), ret.end());
        return ret;
    }
};
