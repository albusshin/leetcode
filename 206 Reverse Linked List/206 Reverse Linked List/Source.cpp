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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *p = head->next, *prev = head;
        head->next = nullptr;
        while (p) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    }
};