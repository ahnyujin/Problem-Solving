class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int count = 0;
        int sum = 0;
        int prev_diff = 2000 + 1; // diff MAX
        for (int i = 1; i < nums.length; i++) {
            int cur_diff = nums[i] - nums[i - 1];
            if (cur_diff != prev_diff) {
                sum += sumFrom1ToN(count);
                count = 0;
            } else {
                count++;
            }
            prev_diff = cur_diff;
        }
        return sum += sumFrom1ToN(count);
    }

    private int sumFrom1ToN(int n) {
        return n * (n + 1) / 2;
    }
}