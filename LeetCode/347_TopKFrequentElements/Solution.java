class The_Comparator implements Comparator<Pair<Integer, Integer>> {
    public int compare(Pair<Integer, Integer> obj1, Pair<Integer, Integer> obj2) {
        return obj2.getKey().compareTo(obj1.getKey());
    }
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        final var hashMap = new HashMap<Integer, Integer>();
        final var pq = new PriorityQueue<Pair<Integer, Integer>>(100000, new The_Comparator());
        for (final var num : nums) {
            Integer count = hashMap.getOrDefault(num, 0);
            hashMap.put(Integer.valueOf(num), count + 1);
        }
        for (final var entry : hashMap.entrySet()) {
            System.out.println(entry.getValue() + " " + entry.getKey());
            pq.add(new Pair<>(entry.getValue(), entry.getKey()));
        }
        int[] ret = new int[k];
        for (int i = 0; i < k; i++) {
            ret[i] = pq.poll().getValue();
        }
        return ret;
    }
}
