class Solution {
    public int lastStoneWeight(int[] stones) {
        final var pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (final var cur : stones) {
            pq.add(cur);
        }
        while (!pq.isEmpty()) {
            int y = pq.poll();
            if (pq.isEmpty()) return y;
            int x = pq.poll();
            if (x != y) {
                pq.add(y - x);
            }
        }
        return 0;
    }
}
