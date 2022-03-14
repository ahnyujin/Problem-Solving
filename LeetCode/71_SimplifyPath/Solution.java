class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<String>();
        for (String cur : path.split("/")) {
            switch (cur) {
                case "":
                case ".":
                    break;
                case "..":
                    if (!stack.isEmpty()) stack.pop();
                    break;
                default:
                    stack.add(cur);
            }
        }
        StringBuilder ret = new StringBuilder();
        for (String cur : stack) {
            ret.append("/");
            ret.append(cur);
        }
        return ret.length() > 0 ? ret.toString() : "/";
    }
}
