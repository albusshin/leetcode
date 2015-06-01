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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int listlen = 0;
        ListNode *p = head;
        ListNode *tail = p;
        while (p) {
            listlen++;
            tail = p;
            p = p->next;
        }
        k %= listlen;
        if (k == 0) return head;
        p = head;
        int counter = listlen - k - 1;
        while (counter--) {
            p = p->next;
        }
        ListNode *ret = p->next;
        p->next = nullptr;
        tail->next = head;
        return ret;
    }
};