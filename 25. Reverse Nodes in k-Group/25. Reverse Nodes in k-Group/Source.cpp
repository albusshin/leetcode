#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	stack<ListNode *> stkp;
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (!head) return head;
        ListNode *ret, *now = head, *next, *p = head, *rp;
		bool complete = true;
		for (int i = 0; i < k - 1; i++) {
			stkp.push(p);
			if (p->next) p = p->next;
			else complete = false;
		}
		if (!complete) return head;
		ret = p;
		rp = ret;
		p = p->next;
		next = p;
		
		while (!stkp.empty()) {
			rp->next = stkp.top();
			stkp.pop();
			rp = rp->next;
		}
		now = next;

		if (!next) {
			rp->next = nullptr;
			return ret;
		}
		for (int i = 0; i < k - 1; i++) {
			stkp.push(p);
			if (p->next) p = p->next;
			else complete = false;
		}
		if (!complete) rp->next = next;
		while (complete) {
			rp->next = p;
			rp = rp->next;
			p = p->next;
			next = p;
			while (!stkp.empty()) {
				rp->next = stkp.top();
				stkp.pop();
				rp = rp->next;
			}
			rp->next = next;
			now = next;

			if (!next) break;
			for (int i = 0; i < k - 1; i++) {
				stkp.push(p);
				if (p->next) p = p->next;
				else complete = false;
			}
		}
		rp->next = next;

		return ret;
    }
};