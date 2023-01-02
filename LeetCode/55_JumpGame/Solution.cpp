class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int last=len-1;
        for(int i=len-1;i>=0;i--){
            if(i+nums[i]>=last){
                last=i;
            }
        }
        return last==0;
    }
};
