class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1, vector<int>(0));
        
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> maxDistance(n+1, 0);
        for (int i=1;i<=n;i++) {
            vector<int> dist(n+1, 0);
            dist[i] = 1;
            queue<int> q;
            q.push(i);

            int length = 1;
            int start = i;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                start = min(start, cur);
                for (int x : adj[cur]) {
                    if (dist[x]==0) {
                        dist[x]=dist[cur]+1;
                        length=max(length, dist[x]);
                        q.push(x);
                    }
                    else if (abs(dist[x]-dist[cur])!=1) {
                        return -1;
                    }
                }
            }
            maxDistance[start] = max(maxDistance[start], length);
        }

        return accumulate(maxDistance.begin(), maxDistance.end(), 0);
    }
};
