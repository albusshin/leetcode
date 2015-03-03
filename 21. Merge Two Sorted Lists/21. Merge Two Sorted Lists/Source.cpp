struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode* head;
		if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;
		else if (l1->val <= l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		ListNode* p = head;

		while (l1 != nullptr && l2 != nullptr) {
			ListNode* tmpp = l1 -> val <= l2 -> val ? l1 : l2;
			if (l1->val <= l2->val) {
				tmpp = l1;
				l1 = l1->next;
			}
			else {
				tmpp = l2;
				l2 = l2->next;
			}
			p = p->next = tmpp;
		}
		if (l1 == nullptr) p ->next = l2;
		else p->next = l1;
		return head;
    }
};