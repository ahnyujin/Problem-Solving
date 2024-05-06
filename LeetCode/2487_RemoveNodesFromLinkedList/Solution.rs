// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }
        
        let mut prev = None;
        let mut curr = head;
        while let Some(mut node) = curr {
            let temp = node.next.take();
            node.next = prev.take();
            prev = Some(node);
            curr = temp;
        }
        curr = prev.as_mut().unwrap().next.take();
        prev.as_mut().unwrap().next = None;
        while let Some(mut node) = curr {
            let next = node.next.take();
            if prev.as_ref().unwrap().val <= node.val {
                node.next = prev;
                prev = Some(node);
            }
            curr = next;
        }
        prev
    }
}