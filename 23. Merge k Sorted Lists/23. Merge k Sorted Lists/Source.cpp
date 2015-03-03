#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = new ListNode(0), *p = head;
		bool empty = true;
		for (auto l : lists) {
			if (l != nullptr) {
				empty = false;
				break;
			}
		}
		while (!empty) {
			auto ite = min_element(lists.begin(), lists.end(), [] (const ListNode* l, const ListNode* r) {
				bool ret = false;
				if (l != nullptr && r != nullptr) ret = l->val < r->val;
				else if (l == nullptr) ret = false;
				else if (r == nullptr) ret = true;
				return ret;
			});
			p->next = *ite;
			p = p->next;
			(*ite) = (*ite)->next;
			empty = true;
			for (auto l : lists) {
				if (l != nullptr) {
					empty = false;
					break;
				}
			}
		}
		ListNode* ret = head->next;
		delete head;
		return ret;
    }
};

int main() {
	Solution s;
	vector<ListNode *> lists;
	ListNode *p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(2);
	ListNode *p2 = new ListNode(1);
	p2->next = new ListNode(1);
	p2->next->next = new ListNode(2);
	lists.push_back(p1);
	lists.push_back(p2);
	auto l = s.mergeKLists(lists);
	for (ListNode* p = l; p != nullptr; p = p->next) {
		cout << p->val;
	}
}