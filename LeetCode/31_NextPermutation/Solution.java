class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        int x = nums[len - 1];
        int x_index = -1;
        int k = 0;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                x = nums[i];
                x_index = i;
                break;
            }
        }
        for (int i = x_index + 1; i < len; i++) {
            if (x < nums[i]) {
                k = i;
            }
        }
        if (xa_index != -1) {
            int temp = nums[k];
            nums[k] = nums[x_index];
            nums[x_index] = temp;
        }
        Arrays.sort(nums, x_index + 1, len);
    }
}
