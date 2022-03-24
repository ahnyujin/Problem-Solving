class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int p_start = 0;
        int p_end = people.length - 1;
        int ret = 0;
        while (p_start <= p_end) {
            if (p_start != p_end && people[p_start] + people[p_end] <= limit) {
                p_start++;
            }
            p_end--;
            ret++;
        }
        return ret;
    }
}
