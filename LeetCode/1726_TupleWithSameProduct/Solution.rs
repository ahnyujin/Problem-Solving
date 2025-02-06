use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut map = HashMap::new();
        let size = nums.len();
        for i in 0..size {
            for j in i+1..size {
                *map.entry(nums[i]*nums[j]).or_insert(0) += 1;
            }
        }; 

        let mut result = 0;
        for &count in map.values() {
            if count > 1 {
                result += 4 * count * (count - 1);
            }
        }

        result
    }
}
