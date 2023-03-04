class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int size=nums.size();
        int minI=INT_MAX;
        int maxI=INT_MAX;
        long long answer=0;
        int last = -1;
        for(int i=0;i<size;i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                if(nums[i]==minK){
                    minI=i;
                }
                if(nums[i]==maxK){
                    maxI=i;
                }
                if(maxI<=i && minI<=i){
                    answer+=(min(minI,maxI)-last);
                }
            }
            else {
                minI=INT_MAX;
                maxI=INT_MAX;
                last = i;
            }
        }
        return answer;
    }
};
