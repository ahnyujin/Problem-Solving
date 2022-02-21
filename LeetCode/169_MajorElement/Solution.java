class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int count = 0;
        for(int cur : nums) {
            if (count == 0) {
                candidate = cur;
            }
            count += (cur == candidate) ? 1 : -1;
        }
        return candidate;
    }
}