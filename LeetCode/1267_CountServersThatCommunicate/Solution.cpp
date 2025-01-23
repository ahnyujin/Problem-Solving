class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int row[250]={0,};
        int col[250]={0,};
        int ret=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ret++;
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&row[i]==1&&col[j]==1){
                    ret--;
                }
            }
        }
        return ret;
    }
};
