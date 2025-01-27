class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for(auto& prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
            degree[prerequisite[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(!degree[i]) q.push(i);
        }

        vector<unordered_set<int>> sets(n);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int x : adj[cur]) {
                degree[x]--;
                if(!degree[x]) q.push(x);

                sets[x].insert(cur);
                sets[x].insert(sets[cur].begin(), sets[cur].end());
            }
        }

        int size = queries.size();
        vector<bool> ret(size);
        for(int i=0;i<size;i++){
            auto pair = queries[i];

            if(sets[pair[1]].find(pair[0]) != sets[pair[1]].end()){
                ret[i]=true;
            }
        }
        return ret;
    }
};
