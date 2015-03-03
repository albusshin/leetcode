#include <vector>
#include <string>
using namespace std;

string alb[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
	vector<string> res;
	vector<string> vs;
	int vsSize;

public:

    vector<string> letterCombinations(string digits) {
		if (digits == "") return res;
		for (char cd : digits) {
			int d = cd - '0';
			vs.push_back(alb[d]);
		}
		string str = "";
		vsSize = vs.size();
		this->calc(str, 0);
		return res;
    }

	void calc(string& str, int level) {
		for (int i=0; i<vs[level].size(); i++) {
			if (level == vsSize - 1) res.push_back(str + vs[level][i]);
			else {
				string s = str + vs[level][i];
				calc(s, level+1);
			}
		}
	};
};