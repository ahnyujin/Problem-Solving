impl Solution {
    pub fn is_array_special(nums: Vec<i32>) -> bool {
        let mut pre=0;
        let size = nums.len();
        pre = nums[0]%2;
        for i in 1..size {
            let cur = nums[i]%2;
            if(cur==pre){
                return false;
            }
            pre=cur;
        }
        return true;
    }
}
