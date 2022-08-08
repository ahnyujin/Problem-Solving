class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vt;
        for(int i=0;i<nums.size();i++){
            auto it = lower_bound(vt.begin(), vt.end(), nums[i]);
            if(it == vt.end()){
                vt.push_back(nums[i]);
            }
            else{
                *it=nums[i];
            }
        }
        return vt.size();
    }
};
