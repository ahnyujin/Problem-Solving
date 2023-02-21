class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        bool flag=false;
        nums.push_back(-1);
        int bef = -1;
        for(auto x : nums){
            if(bef!=x){
                if(flag){
                    return bef;
                }
                flag=true;
            }
            else{
                flag=false;
            }
            bef = x;
        }
        return -1;
    }
};
