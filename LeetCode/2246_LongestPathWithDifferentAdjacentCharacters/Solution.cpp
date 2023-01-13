class Solution {
public:
    int answer=1;
    int dfs(int cur, vector<vector<int>>& adj, string& s) {
        priority_queue<int> pq;
        for(auto next : adj[cur]){
            int len = dfs(next, adj, s);
            if(s[next]!=s[cur]){
                pq.push(len);
            }
        }
        int longestPath = 1;
        int depth = 1;
        for(int i=0;!pq.empty()&&i<2;i++){
            longestPath+=pq.top();
            if(i==0) depth+=pq.top();
            pq.pop();
        }
        answer=max(longestPath,answer);
        return depth;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        int root;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
              root=i;
              continue;
            }
            adj[parent[i]].push_back(i);
        }
        dfs(root, adj, s);
        return answer;
    }
};
