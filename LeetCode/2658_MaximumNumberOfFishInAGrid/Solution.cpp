class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        int ret=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    q.push({i, j});
                    int sum=grid[i][j];
                    grid[i][j]=0;
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int cur_x = x + dx[k];
                            int cur_y = y + dy[k];
                            if(cur_x>=0 && cur_x<m && cur_y>=0 && cur_y<n&&grid[cur_x][cur_y]!=0){
                                sum+=grid[cur_x][cur_y];
                                grid[cur_x][cur_y]=0;
                                q.push({cur_x, cur_y});
                            }
                        }
                    }
                    if(ret<sum){
                        ret=sum;
                    }
                }
            }
        }
        return ret;
    }
};
