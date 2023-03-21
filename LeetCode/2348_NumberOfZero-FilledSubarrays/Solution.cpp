class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ret = 0;
        long long cnt = 0;
        for(auto num : nums){
            if(num==0){
                cnt++;
            }
            else{
                ret+=cnt*(cnt+1)/2;
                cnt = 0;
            }
        }
        return ret+cnt*(cnt+1)/2;
    }
};
