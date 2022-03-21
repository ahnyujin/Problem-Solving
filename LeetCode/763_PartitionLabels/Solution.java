class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> ret = new ArrayList<>();
        int[] check = new int[26];
        for (int i = 0; i < s.length(); i++) {
            check[s.charAt(i) - 'a'] = i;
        }
        int bef = -1;
        int max = -1;
        for (int i = 0; i < s.length(); i++) {
            if (max < check[s.charAt(i) - 'a']) max = check[s.charAt(i) - 'a'];
            if (max == i) {
                ret.add(max - bef);
                bef = max;
            }
        }
        return ret;
    }
}
