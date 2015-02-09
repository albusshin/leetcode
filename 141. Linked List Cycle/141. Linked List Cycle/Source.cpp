//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode *p1 = head, *p2 = head;
		while (true) {
			if (!(p2 && p2->next)) return false;
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2) {
				return true;
			}
		}
    }
};