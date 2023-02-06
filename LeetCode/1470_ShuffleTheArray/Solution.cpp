class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret;
        int y_point=n;
        for(int i=0;i<n;i++){
            ret.push_back(nums[i]);
            ret.push_back(nums[y_point]);
            y_point++;
        }
        return ret;
    }
};
