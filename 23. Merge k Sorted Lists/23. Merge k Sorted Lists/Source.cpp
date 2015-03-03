#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	multimap<int, int> mp;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = new ListNode(0), *p = head;

		int lsize = lists.size();
		for (int i = 0; i < lsize; i++) {
			auto l = lists[i];
			if(l != nullptr) mp.insert(make_pair(l->val, i));
		}

		while (!mp.empty()) {
			p -> next = new ListNode(mp.begin()->first);
			p = p->next;
			int i = mp.begin()->second;
			lists[i] = lists[i]->next;
			mp.erase(mp.begin());
			if (lists[i] != nullptr) mp.insert(make_pair(lists[i]->val, i));
		}

		ListNode* ret = head->next;
		delete head;
		return ret;
    }
};