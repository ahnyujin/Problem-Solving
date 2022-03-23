class Solution {
    public int brokenCalc(int startValue, int target) {
        int ret = 0;
        while (startValue < target) {
            ret++;
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
        }
        return ret + startValue - target;
    }
}
