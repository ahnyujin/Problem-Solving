class Solution {
    public boolean backspaceCompare(String s, String t) {
        int p_s = s.length() - 1;
        int p_t = t.length() - 1;
        p_s = nextIndex(s, p_s);
        p_t = nextIndex(t, p_t);
        while (p_s >= 0 && p_t >= 0) {
            if (s.charAt(p_s) != t.charAt(p_t)) break;
            p_s = nextIndex(s, p_s - 1);
            p_t = nextIndex(t, p_t - 1);
        }
        return p_s == -1 && p_t == -1;
    }

    private int nextIndex(String x, int index) {
        int count = 0;
        while (index >= 0) {
            if (x.charAt(index) == '#') {
                count++;
            } else {
                count--;
            }
            if (count == -1) break;
            index--;
        }
        return index;
    }
}
