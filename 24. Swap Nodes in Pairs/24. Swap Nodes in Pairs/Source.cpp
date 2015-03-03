struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		if (!head) return head;
		if (!head->next) return head;
		ListNode* p = head;
		head = head->next;
		while (true) {
			ListNode* second = p->next;
			if (second->next) {
				if (second->next->next) {
					p->next = second->next->next;
					ListNode* tmpp = p;
					p = second->next;
					second->next = tmpp;
				}
				else {
					p -> next = second->next;
					second->next = p;
					return head;
				}
			}
			else {
				p -> next = nullptr;
				second->next = p;
				return head;
			}
		}
    }
};