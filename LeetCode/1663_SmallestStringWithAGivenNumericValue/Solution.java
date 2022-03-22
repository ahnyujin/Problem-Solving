class Solution {
    public String getSmallestString(int n, int k) {
        StringBuilder ret = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int cur;
            if ((n - 1 - i) * 26 >= k - 1) cur = 1;
            else {
                cur = k - (n - 1 - i) * 26;
            }
            ret.append((char) (cur + 96));
            k -= cur;
        }
        return ret.toString();
    }
}
