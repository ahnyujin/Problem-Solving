class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int size = nums.size();
        int answer=0;
        for(int i=2;i<size;i++){
            if(nums[i-1] == (nums[i-2]+nums[i])*2){
                answer++;
            }
        }
        return answer;
    }
};
