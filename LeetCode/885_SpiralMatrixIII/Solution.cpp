class Solution {
public:
    int xl[4] = {1, 0, -1, 0};
    int yl[4] = {0, -1, 0, 1};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans = {{rStart, cStart}};
        for(int t=1;;t++){
            int x = rStart-t;
            int y = cStart+t;
            vector<vector<int>> ret;
            for(int i=0;i<4;i++){
                for(int j=0;j<2*t;j++){
                    x+=xl[i];
                    y+=yl[i];
                    if(x>=0 && y>=0 && x<rows && y<cols){
                        ret.push_back({x,y});
                    }
                }
            }
            if(ret.size() == 0 ) return ans;
            ans.insert(ans.end(), ret.begin(), ret.end());
        }
        return ans;
    }
};
