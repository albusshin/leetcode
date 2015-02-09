#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
private:
	vector<ListNode*> ps;
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next == NULL) return false;
        ListNode *p = head->next;
		while (find(ps.begin(), ps.end(), p) == ps.end()) {
			ps.push_back(p);
            if (p->next == NULL) return false;
            else p = p->next;
        }
        return true;
    }
};