#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	vector<ListNode *> vp;
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *p = head;
		while (p) {
			vp.push_back(p);
			p = p->next;
		}
		auto rite = vp.rbegin();
		rite += n - 1;
		if (rite == vp.rend() - 1) return head->next;
		(*(rite + 1)) -> next = (*rite)->next;
		delete (*rite);
		return head;
    }
};