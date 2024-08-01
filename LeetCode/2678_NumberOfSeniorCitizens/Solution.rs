impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        let mut ret = 0;
        for detail in &details {
            let digits = &detail[11..13];
            let number: u32 = digits.parse().expect("Invalid Number!");
            if(number>60) {
                ret+=1;
            }
        }
        return ret;
    }
}
