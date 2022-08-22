class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(map.find(target-nums[i])!=map.end()){
                return {map[target-nums[i]], i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
