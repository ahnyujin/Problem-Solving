class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> table(1001);
        for(auto num : nums1) {
            table[num[0]]+=num[1];
        }

        for(auto num : nums2) {
            table[num[0]]+=num[1];
        }

        vector<vector<int>> ret;
        for(int i=1;i<=1000;i++){
            if(table[i]!=0){
                ret.push_back({i, table[i]});
            }
        }
        return ret;
    }
};
