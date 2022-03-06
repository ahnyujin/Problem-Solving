class Solution {
    public int countOrders(int n) {
        long ret = 1;
        int modulo = 1000000007;
        for (int i = 1; i <= 2 * n; i++) {
            ret = ret * i;
            if (i % 2 == 0) {
                ret = ret / 2;
            }
            if (ret >= modulo) {
                ret %= modulo;
            }
        }
        return (int) ret;
    }
}