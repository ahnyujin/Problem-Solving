/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = new ListNode();
        ListNode* cur = ret;
        int size = lists.size();
        int min_index;
        while(min_index!=-1){
            int min = INT_MAX;
            min_index = -1;
            for(int i=0;i<size;i++){
                if(lists[i] != nullptr){
                    if(min>(lists[i]->val)){
                        min = lists[i]->val;
                        min_index = i;
                    }
                }
            }
            if(min_index!=-1){
                cur->next = new ListNode;
                cur = cur -> next;
                cur->val = min;
                lists[min_index] = lists[min_index]->next;
            }
        }
        return ret->next;
    }
};
