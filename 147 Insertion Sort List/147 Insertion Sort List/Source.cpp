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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p = head,
                 *next = head->next;
        head->next = nullptr;
        while (next) {
            ListNode *nnext = next->next;
            ListNode *p1 = head;
            ListNode *prev = nullptr;
            while (p1 && p1->val < next->val) {
                prev = p1;
                p1 = p1->next;
            }
            if (!prev) {
                next->next = head;
                head = next;
            }
            else {
                prev->next = next;
                next->next = p1;
            }
            next = nnext;
        }
        return head;
    }
};