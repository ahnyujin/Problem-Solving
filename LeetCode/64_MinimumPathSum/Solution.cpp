class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int minimum = INT_MAX;
                if(i!=0){
                    minimum = grid[i-1][j];
                }
                if(j!=0){
                    minimum = min(minimum,grid[i][j-1]);
                }
                if(minimum!=INT_MAX){
                    grid[i][j]+=minimum;
                }
            }
        }
        return grid[m-1][n-1];
    }
};
