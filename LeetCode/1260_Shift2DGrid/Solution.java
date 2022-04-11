class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        List<List<Integer>> ret = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>();
            ret.add(row);
            for (int j = 0; j < n; j++) {
                int index = (i * n + j - k + 100 * m * n) % (m * n);
                row.add(grid[index / n][index % n]);
            }
        }
        return ret;
    }
}
