class Solution {
public:
    int uniquePaths(int m, int n) {
        int table[n];
        for(int i=0;i<n;++i){
            table[i]=1;
        }
        for (int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                table[j]=table[j]+table[j-1];
            }
        }
        return table[n-1];
    }
};
