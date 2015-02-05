#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		string::iterator ite;
		stack<char> stk;
		for (ite=s.begin(); ite!=s.end(); ite++)
		{
			char c = *ite;
			if (c == '(' || c == '[' || c == '{')
			{
				stk.push(c);
			}
			else
			{
				if (stk.size() == 0) return false;
				bool match = false;
				char t = stk.top();
				if ((t == '{' && c != '}') || (t == '[' && c != ']') || (t == '(' && c != ')')) return false;
				stk.pop();
			}
		}
		if (stk.size() != 0) return false;
		return true;
    }
};