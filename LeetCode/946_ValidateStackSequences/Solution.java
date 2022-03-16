class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack();
        int p_popped = 0;
        for (int cur : pushed) {
            stack.push(cur);
            while (!stack.isEmpty() && stack.peek() == popped[p_popped]) {
                p_popped++;
                stack.pop();
            }
        }
        return p_popped == popped.length;
    }
}
