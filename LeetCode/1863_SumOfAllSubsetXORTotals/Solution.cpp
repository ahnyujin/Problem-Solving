class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> table;
        int sum=0;
        for(auto num : nums){
            vector<int> vt;
            vt.push_back(num);
            sum+=num;
            for(auto x : table){
                int cur = x^num;
                vt.push_back(cur);
                sum+=cur;
            }
            table.insert(table.end(), vt.begin(), vt.end());
        }
        return sum;
    }
};
