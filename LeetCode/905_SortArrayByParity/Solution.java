class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int p_first = 0;
        int p_second = nums.length - 1;
        while (p_first < p_second) {
            if (nums[p_first] % 2 == 1 && nums[p_second] % 2 == 0) {
                nums[p_first] += nums[p_second];
                nums[p_second] = nums[p_first] - nums[p_second];
                nums[p_first] -= nums[p_second];
            }
            if (nums[p_first] % 2 == 0) p_first++;
            if (nums[p_second] % 2 == 1) p_second--;
        }
        return nums;
    }
}
