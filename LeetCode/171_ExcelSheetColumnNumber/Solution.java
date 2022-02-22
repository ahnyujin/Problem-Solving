class Solution {
    public int titleToNumber(String columnTitle) {
        int ret = 0;
        for(char cur : columnTitle.toCharArray()) {
            ret *= 26;
            ret += cur-'A'+1;
        }
        return ret;
    }
}