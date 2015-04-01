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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        for (; p; p=p->next) {
            ListNode *p2 = p;
            for (; p2 && p2->val == p->val; p2 = p2->next);
            p->next = p2;
        }
        return head;
    }
};