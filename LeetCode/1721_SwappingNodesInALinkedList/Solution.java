/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode cur = head;
        ListNode k_beg = head;
        ListNode k_end = head;
        int count = 0;
        while (cur != null) {
            count++;
            if (count == k) {
                k_beg = cur;
            }
            if (count > k) {
                k_end = k_end.next;
            }
            cur = cur.next;
        }
        swapNodesValue(k_beg, k_end);
        return head;
    }

    private void swapNodesValue(ListNode x, ListNode y) {
        int temp = x.val;
        x.val = y.val;
        y.val = temp;
    }
}
