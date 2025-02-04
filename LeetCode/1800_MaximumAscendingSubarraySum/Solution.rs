impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut sum = nums[0];
        let mut ret = sum;
        for i in 1..n {
            if(nums[i] > nums[i-1]) {
                sum+=nums[i];
            } else {
                sum=nums[i];
            }
            if(sum > ret){
                ret=sum;
            }
        }
        return ret;
    }
}
