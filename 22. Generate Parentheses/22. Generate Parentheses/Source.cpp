#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
 
class Solution {
	string now;
	vector<string> res;
	int n;
public:
    vector<string> generateParenthesis(int n) {
		this->n = n;
		stringstream ss;
		int nc = n;
		while (nc--) ss << '(';
		nc = n;
		while (nc--) ss << ')';
		ss >> now;
		res.push_back(now);
		bt();
		return res;
    }

	void bt() {
		while (true) {
			for(int i = 1; i <= n; i++) { //find the i-st reverse '('
				int j = 0, k ;
				for (k = now.length() - 1; k >= 0 && j != i; k--) {
					if (now[k] == '(') j++;
				}
				k++;
				string nowcp = now.substr(0, k);
				int l = 0, r = 0;
				nowcp += ')';
				for (auto c : nowcp) {
					if (c == '(') l++;
					else r++;
				}
				if (r > l) { //not valid
					if (i == n) return;
					continue;
				}
				for (j = 0; j < n - l; j++) nowcp += '(';
				for (j = 0; j < n - r; j++) nowcp += ')';
				now = nowcp;
				res.push_back(now);
				break; //backtracked
			}
		}
	}
};