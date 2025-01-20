class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> table(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                table[mat[i][j]]= make_pair(i,j);
            }
        }

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int size = arr.size();
        for(int i=0;i<size;i++){
            auto [x, y] = table[arr[i]];
            if(++row[x] == n){
                return i;
            }
            if(++col[y] == m){
                return i;
            }
        }
        return -1;
    }
};
