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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        int len = 0, front, back;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        if (len < 3) return;
        front = (len + 1) / 2;
        back = len - front;
        p = head;
        int tmp = front;
        while (tmp--) {
            p = p->next;
        }
        while (p) {
            stk.push(p);
            p = p->next;
        }
        p = head;
        while (!stk.empty()) {
            ListNode* next = p->next;
            ListNode* b = stk.top();
            stk.pop();
            p->next = b;
            b->next = next;
            if (stk.empty())
                next->next = nullptr;
            else 
                p = next;
        }
    }
};