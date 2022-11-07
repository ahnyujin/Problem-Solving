class Solution {
public:
    int table[10005];
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                table[mat[i][j]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(table[mat[m-1][i]]==m){
                return mat[m-1][i];
            }
        }
        return -1;
    }
};
