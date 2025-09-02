class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            if(a[0] == b[0])return a[1] > b[1];
            return a[0] < b[0];
        });

        int result = 0;
        for(int i=0;i<n;i++){
            int baseY=points[i][1];
            int lastY=INT_MIN;
            for(int j=i+1;j<n;j++){
                int y=points[j][1];
                if(lastY<y&&y<=baseY){
                    result++;
                    lastY=y;
                    if(lastY==baseY)break;
                }
            }
        }
        return result;
    }
};
