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
    int listLen(ListNode *head) {
        ListNode *p = head;
        int ret = 0;
        while (p) {
            ret++;
            p = p->next;
        }
        return ret;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        int lena = listLen(headA), lenb = listLen(headB);
        int lendiff = abs(lena - lenb);
        if (lena > lenb) while (lendiff--) pa = pa->next;
        else while (lendiff--) pb = pb->next;
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};