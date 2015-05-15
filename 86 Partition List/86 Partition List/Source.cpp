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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(0), *l2 = new ListNode(0);
        ListNode *l1head = l1, *l2head = l2, *p = head;
        while (p) {
            ListNode *next = p->next;
            if (p->val < x) {
                l1->next = p;
                l1 = p;
            } else {
                l2->next = p;
                l2 = p;
            }
            p = next;
        }
        l1->next = l2head->next;
        l2->next = nullptr;
        return l1head->next;
    }
};