class Solution {
    public int maxArea(int[] height) {
        int p_left = 0;
        int p_right = height.length - 1;
        int ret = 0;
        while (p_left < p_right) {
            int min_height = Math.min(height[p_left], height[p_right]);
            int width = p_right - p_left;
            if (ret < min_height * width) ret = min_height * width;
            if (height[p_left] < height[p_right]) {
                p_left++;
            } else {
                p_right--;
            }
        }
        return ret;
    }
}
