#define NULL 0

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next == NULL) return false;
        ListNode *p = head->next;
        while (p != head) {
            if (p->next == NULL) return false;
            else p = p->next;
        }
        return true;
    }
};