class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid = (start+end)/2;
        while(start<end) {
            if(nums[mid]==target){
                break;
            }
            if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = (start+end)/2;
        }
        return mid;
    }
};
