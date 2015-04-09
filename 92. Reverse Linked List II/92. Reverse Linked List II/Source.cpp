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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *tmphead = nullptr, *prevhead = nullptr;
        ListNode *toremove = new ListNode(0);
        toremove->next = head;
        ListNode *p = toremove;
        int counter = 1;
        for (int i = 0; i < m - 1; i++) {
            p = p->next;
            counter++;
        }
        prevhead = p;
        //m
        p = p->next;
        counter++;
        tmphead = p;
        ListNode* prev = p;
        p = p->next;
        counter++;
        //m+1
        
        while (counter <= n) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            counter++;
            p = next;
        }
        //n
        prevhead->next = p;
        tmphead->next = p->next;
        p->next = prev;
        ListNode *ret = toremove->next;
        delete toremove;
        return ret;
    }
};