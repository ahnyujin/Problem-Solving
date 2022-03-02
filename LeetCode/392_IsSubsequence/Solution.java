class Solution {
    public boolean isSubsequence(String s, String t) {
        int index = 0;
        for (int i = 0; i < t.length(); i++) {
            char cur = t.charAt(i);
            if (index == s.length()) break;
            if (cur == s.charAt(index)) {
                index++;
            }
        }
        return index == s.length();
    }
}
