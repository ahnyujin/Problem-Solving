class Solution {
    public String minRemoveToMakeValid(String s) {
        int p_left = 0;
        int p_right = 1;
        int cnt = 0;
        StringBuilder ret = new StringBuilder();
        while (p_left < s.length()) {
            System.out.println(p_left + " " + p_right);
            char left = s.charAt(p_left);
            if (left == '(') {
                if (p_left > p_right) p_right = p_left;
                if (p_right == s.length()) {
                    p_left++;
                    continue;
                } else if (s.charAt(p_right) == ')') {
                    cnt++;
                    ret.append(left);
                    p_left++;
                    p_right++;
                } else {
                    p_right++;
                }
            } else if (left == ')') {
                if (cnt > 0) {
                    ret.append(left);
                    cnt--;
                }
                p_left++;
            } else {
                ret.append(left);
                p_left++;
            }
        }
        return ret.toString();
    }
}
