class Solution {
    public boolean isValid(String s) {
        boolean ret = false;
        Stack<Character> stack = new Stack<Character>();
        HashMap<Character, Character> hashMap = new HashMap<Character, Character>();
        hashMap.put(')', '(');
        hashMap.put('}', '{');
        hashMap.put(']', '[');
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (!hashMap.containsKey(cur)) {
                stack.push(cur);
            } else if (stack.empty() || stack.pop() != hashMap.get(cur)) {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
