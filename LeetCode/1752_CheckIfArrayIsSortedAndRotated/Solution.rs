impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let size = nums.len();
        let mut cnt = 0;
        for i in 0..size {
            if nums[i] > nums[(i+1)%size] {
                cnt += 1;
            }
        }
        cnt <= 1
    }
}
