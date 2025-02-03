impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size == 0 {
            return 0;
        }

        let mut ret = 1;
        let mut inc = 1;
        let mut dec = 1;
        for i in 1..size {
            if nums[i] > nums[i - 1] {
                inc += 1;
                dec = 1
            } else if nums[i] < nums[i - 1] {
                inc = 1;
                dec += 1;
            } else {
                inc = 1;
                dec = 1;
            }

            ret = ret.max(inc).max(dec);
        }

        ret
    }
}
