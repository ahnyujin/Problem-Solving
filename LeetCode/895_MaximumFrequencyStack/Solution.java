class The_Comparator implements Comparator<Pair<Integer, Pair<Integer, Integer>>> {
    public int compare(Pair<Integer, Pair<Integer, Integer>> obj1, Pair<Integer, Pair<Integer, Integer>> obj2) {
        int ret = obj2.getKey().compareTo(obj1.getKey());
        return ret == 0 ? obj2.getValue().getKey().compareTo(obj1.getValue().getKey()) : ret;
    }
}

class FreqStack {
    PriorityQueue<Pair<Integer, Pair<Integer, Integer>>> pq;
    HashMap<Integer, Integer> check;
    int index;

    public FreqStack() {
        check = new HashMap<Integer, Integer>();
        pq = new PriorityQueue<>(30000, new The_Comparator());
        index = 0;
    }

    public void push(int val) {
        index++;
        int count = check.getOrDefault(val, 0) + 1;
        check.put(val, count);
        Pair<Integer, Integer> temp = new Pair<>(index, val);
        Pair<Integer, Pair<Integer, Integer>> pair = new Pair<>(count, temp);
        pq.add(pair);
    }

    public int pop() {
        int head = pq.poll().getValue().getValue();
        check.put(head, check.get(head) - 1);
        return head;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */
