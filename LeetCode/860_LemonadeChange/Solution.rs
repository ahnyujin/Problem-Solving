impl Solution {
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        let mut wallet: [i32; 2] = [0, 0];
        for bill in bills {
            if bill == 5 {
                wallet[0] = wallet[0]+1;
            } else if bill == 10 {
                if wallet[0] > 0 {
                    wallet[0] -= 1;
                } else {
                    return false;
                }
                wallet[1]=wallet[1]+1;
            } else if bill == 20 {
                if wallet[1] > 0 && wallet[0] > 0 {
                    wallet[0] -= 1;
                    wallet[1] -= 1;
                } else if wallet[0] >= 3 {
                    wallet[0] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true; 
    }
}
