class Solution {
    public int[] countBits(int n) {
        int[] ret = new int[n + 1];
        for (int index = 0; index <= n; index++) {
            ret[index] = ret[index / 2] + index % 2;
        }
        return ret;
    }
}