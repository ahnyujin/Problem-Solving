class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        List<List<Integer>> resuult = new ArrayList();
        for (int i = (int) Math.pow(2, n); i < (int) Math.pow(2, n + 1); ++i) {
            String bitmask = Integer.toBinaryString(i).substring(1);
            List<Integer> subset = new ArrayList();
            for (int j = 0; j < n; ++j) {
                if (bitmask.charAt(j) == '1') subset.add(nums[j]);
            }
            result.add(subset);
        }
        return result;
    }
}