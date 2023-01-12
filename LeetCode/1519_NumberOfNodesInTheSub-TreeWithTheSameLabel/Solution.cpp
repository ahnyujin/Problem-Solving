class Solution {
public:
    vector<int> dfs(int cur, vector<vector<int>>& adj, string &labels, vector<int>& answer){
        vector<int> sum(26,0);
        answer[cur]=1;
        
        for(int next : adj[cur]){
            if(!answer[next]){
                vector<int> subtreeSum = dfs(next, adj, labels, answer);
                for(int i=0;i<26;i++){
                    sum[i]+=subtreeSum[i];
                }
            }
        }
        answer[cur] = ++sum[labels[cur]-'a'];
        return sum;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> answer(n,0);
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, adj, labels, answer);
        return answer;
    }
};
