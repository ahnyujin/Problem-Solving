class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int end=points[0][1];
        int ret = 1;
        for(auto point : points){
            if(point[0]>end){
                ret++;
                end=point[1];
            }
            end = min(point[1], end);
        }
        return ret;
    }
};
