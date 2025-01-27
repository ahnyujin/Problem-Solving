class Solution {
public:
    int maximumInvitations(vector<int>& favorites) {
        int n = favorites.size();
        vector<int> degree(n, 0);
        for(auto x : favorites) {
            degree[x]++;
        }

        queue<int> q;
        vector<int> table(n, 0);
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }

        vector<bool> visited(n, false);
        while(!q.empty()){
            int cur = q.front();
            visited[cur] = true;
            q.pop();

            int favorite=favorites[cur];
            table[favorite]=table[cur]+1;
            if (--degree[favorite]==0){
                q.push(favorite);
            }
        }
        int maxCount=0;
        int cycleChains=0;
        for(int i=0;i<n;i++){
            if(vi)
            if(!visited[i]){
                int cur = i;
                int cnt = 0;
                while(!visited[cur]){
                    visited[cur] = true;
                    cur = favorites[cur];
                    cnt++;
                }
                if(cnt==2){
                    cycleChains += table[i]+table[favorites[i]]+2;
                }else{
                    maxCount = max(maxCount, cnt);
                }
            }
        }
        return max(maxCount, cycleChains);
    }
};
