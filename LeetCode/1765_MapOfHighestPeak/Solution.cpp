class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n, -1));
        queue<int> q;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push(i*n+j);
                    ret[i][j]=0;
                }
            }
        }
        
        while (!q.empty()) {
            int front = q.front();
            int cur_x = front / n;
            int cur_y = front % n;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur_x + dx[i];
                int y = cur_y + dy[i];
                if(x<0 || y<0 ||x>=m || y>=n) continue;
                if (ret[x][y] == -1){
                    q.push(x * n + y);
                    ret[x][y] = ret[cur_x][cur_y]+1;
                }
            }
        }
        return ret;
    }
};
