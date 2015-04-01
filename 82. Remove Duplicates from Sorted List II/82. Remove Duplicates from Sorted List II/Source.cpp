struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if (!head) return nullptr;
		ListNode *h = new ListNode(head->val - 1);
		h->next = head;
		ListNode *prev = h, *p = head;
		while (p) {
			bool flag = false;
			while (p && p->next && p->val == p->next->val){
				p = p->next;
				flag = true;
			}
			if (flag) p = p->next;
			if (p && p->next && p->val == p->next->val) continue;
			prev->next = p;
			prev = p;
			if (p) p = p->next;
		}
		
		ListNode *ret = h->next;
		delete h;
		return ret;
    }
};