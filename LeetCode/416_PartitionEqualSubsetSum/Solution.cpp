class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto num : nums){
            totalSum+=num;
        }

        if(totalSum%2!=0) return false;
        int sum = totalSum/2;

        vector<int> table(10001, 0);
        for(auto num : nums) {
            for(int i=sum;i>=num;i--){
                if(i-num==0 || table[i-num]!=0){
                    table[i]=1;
                }
            }
        }
        return table[sum];
    }
};
