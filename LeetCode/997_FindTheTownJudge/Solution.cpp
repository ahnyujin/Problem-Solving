class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> check(n, vector<int> (2,0));
        for(auto x : trust) {
            check[x[0]-1][0]++;
            check[x[1]-1][1]++;
        }
        for(int i=0;i<n;i++){
            if(check[i][0]==0 && check[i][1]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};
