impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        assert_eq!(s1.len(), s2.len());

        let mut diffs = [0, 0];
        let mut diff_count = 0;

        let mut index = 0;
        for (c1, c2) in s1.chars().zip(s2.chars()) {
            if c1 != c2 {
                if diff_count >= 2 {
                    return false;
                }

                diffs[diff_count] = index;
                diff_count += 1;
            }
            index += 1;
        }

        if diff_count != 0 && diff_count != 2 {
            return false;
        }

        let s1_diff1 = s1.chars().nth(diffs[0]).unwrap();
        let s1_diff2 = s1.chars().nth(diffs[1]).unwrap();

        let s2_diff1 = s2.chars().nth(diffs[0]).unwrap();
        let s2_diff2 = s2.chars().nth(diffs[1]).unwrap();

        s1_diff1 == s2_diff2 && s1_diff2 == s2_diff1
    }
}
