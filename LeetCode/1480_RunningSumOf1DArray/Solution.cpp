class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> ret;
        for(int num : nums) {
            sum+=num;
            ret.push_back(sum);
        }
        return ret;
    }
};
