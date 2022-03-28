class Solution {
    public boolean search(int[] nums, int target) {
        return binary_search(0, nums.length - 1, nums, target);
    }

    private boolean binary_search(int left, int right, int[] nums, int target) {
        if (left > right) return false;
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] <= nums[left] && nums[mid] <= nums[right])
            return binary_search(left, mid - 1, nums, target) || binary_search(mid + 1, right, nums, target);
        if (nums[left] <= target && nums[mid] >= target) return binary_search(left, mid - 1, nums, target);
        return binary_search(mid + 1, right, nums, target);
    }
}
