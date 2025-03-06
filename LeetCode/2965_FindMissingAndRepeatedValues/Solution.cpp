class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        boolean[] table = new boolean[n*n+1];
        int m = n*n;
        int total = m*(m+1)>>1;
        int sum =0;
        int[] ans = new int[2];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cur = grid[i][j];
                sum+=cur;
                if(table[cur]){
                    ans[0] = cur;
                }
                table[cur]=true;
            }
        }
        ans[1] = total - sum + ans[0];
        return ans;
    }
}
