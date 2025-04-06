class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return {nums[0]};

        sort(nums.begin(), nums.end());
        vector<int> table(size, 0);
        vector<int> rec(size, -1);
        table[0]=1;
        int total_max_index = 0;
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && table[j]>table[i]){
                    table[i]=table[j];
                    rec[i]=j;
                }
            }
            table[i]=table[i]+1;
            if(table[i]>table[total_max_index]){
                total_max_index = i;
            }
        }

        vector<int> ret;
        int x = total_max_index;
        while(x>=0){
            ret.push_back(nums[x]);
            x=rec[x];
        }
        return ret;
    }
};
