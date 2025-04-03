class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ret=0;
        int max=nums[0];
        long long prev = 0;
        for(int k=1;k<n;k++){
            if(ret<prev*nums[k]){
                ret=prev*nums[k];
            }

            if(max-nums[k]>prev){
                prev=max-nums[k];
            }

            if(max<nums[k]){
                max=nums[k];
            }
        }
        return ret;
    }
};
