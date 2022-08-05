class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned long long table[target+1];
        memset(table, 0, sizeof table);
        table[0]=1;
        for(int i=1;i<=target;++i) {
            for(int num : nums){
                if(i-num>=0){
                    table[i]+=table[i-num];
                }
            }
        }
        return table[target];
    }
}
