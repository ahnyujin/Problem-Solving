class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int size = nums.size();
        
        int ret = size/3;
        vector<int> table(101, 0);
        
        for(int i=size-1;i>=ret*3;i--){
            if(table[nums[i]]==1){
                return ret+1;
            }
            table[nums[i]]++;
        }
        for(int i=ret-1;i>=0;i--){
            for(int j=2;j>=0;j--){
                if(table[nums[i*3+j]]==1){
                    return i+1;
                }
                table[nums[i*3+j]]++;
            }
        }
        return 0;
    }
};
