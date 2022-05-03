class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        int start = -1;
        int end = -1;
        for (int i = 0; i < nums.length; i++) {
            if (sortedNums[i] != nums[i]) {
                if (start == -1) start = i;
                end = i;
            }
        }
        return start == -1 ? 0 : end - start + 1;
    }
}
