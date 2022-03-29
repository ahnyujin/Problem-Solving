class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for (int cur : nums) {
            if (set.contains(cur)) {
                return cur;
            }
            set.add(cur);
        }
        return -1;
    }
}
