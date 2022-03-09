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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode ret = new ListNode(-200);
        ret.next = head;
        ListNode p = ret;
        ListNode p_next = p.next;
        while (p_next != null) {
            if (p.next.val != p_next.val) {
                if (p.next.next == p_next) {
                    p = p.next;
                } else {
                    p.next = p_next;
                }
            }
            p_next = p_next.next;
        }
        if (p.next != null && p.next.next != null) p.next = null;
        return ret.next;
    }
}