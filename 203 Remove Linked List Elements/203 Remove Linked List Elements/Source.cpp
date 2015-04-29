/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmpHead = new ListNode(-1);
        tmpHead->next = head;
        ListNode *prev = tmpHead;
        ListNode *p = head;
        while (p) {
            if (p->val == val) {
                prev->next = p->next;
                
            } else {
                prev = p;
            }
            p = p->next;
        }
        return tmpHead->next;
    }
};