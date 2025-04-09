class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = -1;
        int ret = 0;
        int min = 100;
        for(auto x : nums){
            if(prev !=x ) {
                ret++;
            }
            prev = x;
            if(x < min){
                min = x;
            }
        }
        if(k>min){
            return -1;
        }
        if(k==min){
            return ret-1;
        }
        return ret;
    }
};
