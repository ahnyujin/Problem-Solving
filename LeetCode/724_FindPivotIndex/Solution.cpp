class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum+=num;
        }

        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(count*2+nums[i]==sum) return i;
            count+=nums[i];
        }
        return -1;
    }
};
