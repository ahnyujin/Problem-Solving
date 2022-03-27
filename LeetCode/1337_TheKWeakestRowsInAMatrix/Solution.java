class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1];
            else return a[0] - b[0];
        });
        for (int i = 0; i < mat.length; i++) {
            for (int j = 1; j < mat[i].length; j++) {
                mat[i][j] += mat[i][j - 1];
            }
            pq.add(new int[]{mat[i][mat[i].length - 1], i});
        }
        int[] ret = new int[k];
        for (int i = 0; i < k; i++) {
            int[] cur = pq.poll();
            ret[i] = cur[1];
        }
        return ret;
    }
}
