class Solution {
    // Time Complexity: O(R^2)
    // Space Complexity: O(R^2)
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] table = new double[query_row + 2][query_row + 2];
        table[0][0] = (double) poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (table[i][j] > 1.0) {
                    double half = (table[i][j] - 1.0) / 2.0;
                    table[i + 1][j] += half;
                    table[i + 1][j + 1] += half;
                    table[i][j] = 1;
                }
                if(query_glass==j) break;
            }
        }
        return table[query_row][query_glass];
    }
}