class Solution {
    private static int MIN_INTERVAL_NUMBER = 0;

    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] == o2[0] ? o2[1] - o1[1] : o1[0] - o2[0];
            }
        });
        int ret = 0;
        int max = MIN_INTERVAL_NUMBER - 1;
        for (int[] cur : intervals) {
            if (max < cur[1]) {
                ret++;
                max = cur[1];
            }
        }
        return ret;
    }
}