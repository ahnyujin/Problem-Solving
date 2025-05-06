class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> vt;
        for(int i = 0;i < size ;i++){
            vt.push_back(nums[nums[i]]);
        }
        return vt;
    }
};
