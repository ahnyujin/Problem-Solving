class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int xl[4] = {-1, 0, 1 ,0};
        int yl[4] = {0, 1, 0, -1};
        int ret = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int> cur = q.front();
            int i = cur.first;
            int j = cur.second;
            q.pop();
            for(int k=0;k<4;k++){
                if(i+xl[k]<m && i+xl[k] >=0 && j+yl[k]<n && j+yl[k] >=0 && grid[i+xl[k]][j+yl[k]]==0){
                    grid[i+xl[k]][j+yl[k]]=grid[i][j]+1;
                    q.push({i+xl[k], j+yl[k]});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>1 && ret < grid[i][j]){
                    ret = grid[i][j];
                }
            }
        }
        return ret-1;
    }
};
