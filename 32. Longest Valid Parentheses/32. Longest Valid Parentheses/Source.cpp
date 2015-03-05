#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
	stack<pair<char, int>> stk;
	vector<pair<int, int>> v; //first: length; second: ending index
public:
    int longestValidParentheses(string s) {
		if (s.empty()) return 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c == '(') stk.push(make_pair(c, i));
			else if (!stk.empty()){
				auto pci = stk.top();
				stk.pop();
				auto ite = v.begin();
				for (; ite != v.end(); ++ite) {
					if (ite->second == pci.second - 1) {
						ite->first += i - pci.second + 1;
						ite->second = i;
					};
				}
				if (ite == v.end()) {
					v.push_back(make_pair(i - pci.second + 1, i));
				}
			}
			else { //stk.empty()
				continue;
			}
		}
		auto ret = max_element(v.begin(), v.end(), [](const pair<int, int>& pl, const pair<int, int>& pr){
			return pl.first < pr.first;
		});
		if (ret == v.end()) return 0;
		return ret->first;
    }
};