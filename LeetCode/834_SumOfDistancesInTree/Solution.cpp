class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vt(n);
        vector<int> count(n,1);
        vector<int> ret(n,0);
        for(auto it : edges){
            vt[it[0]].push_back(it[1]);
            vt[it[1]].push_back(it[0]);
        }
        dfs(0,-1,vt,count,ret);
        dfs2(n,0,-1,vt,count,ret);
        return ret;
    }
    void dfs(int cur, int pre, vector<vector<int>>& vt, vector<int>& count, vector<int>& ret){
        for(auto x:vt[cur]){
            if(x!=pre){
                dfs(x, cur, vt, count, ret);
                count[cur]+=count[x];
                ret[cur]+=ret[x]+count[x];
            }
        }
    }
    void dfs2(int n, int cur, int pre, vector<vector<int>>& vt, vector<int>& count, vector<int>& ret){
        for(auto x:vt[cur]){
            if(x!=pre){
                ret[x]=ret[cur]-count[x]+n-count[x];
                dfs2(n, x, cur, vt, count, ret);
            }
        }
    }
};
