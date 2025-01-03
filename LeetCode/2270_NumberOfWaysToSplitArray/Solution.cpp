class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        set<int> my_set;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long acc = 0;
        int ret = 0;
        int size = nums.size();
        for(int i=0;i<size-1;i++){
            acc+=nums[i];
            if (acc*2>=sum){
                ret++;
            }
        }
        return ret;
    }
};
