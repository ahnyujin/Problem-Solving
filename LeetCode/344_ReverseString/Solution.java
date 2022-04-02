class Solution {
    public void reverseString(char[] s) {
        int len = s.length;
        for (int i = 0; i < len / 2; i++) {
            exchangeTwoChar(s, i, len - i - 1);
        }
    }

    private void exchangeTwoChar(char[] s, int x, int y) {
        char temp = s[x];
        s[x] = s[y];
        s[y] = temp;
    }
}
