#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
		if (s.size() == 0 || nRows == 1)
		{
			return s;
		}
		vector<vector<char>> zz;
		zz.resize(nRows);
		string ret = "";
		int i=0, k=0;
		bool down = true;
		zz[0].push_back(s[0]);
		for (k=1; k<s.size(); k++)
		{
			if (down)
			{
				i++;
				zz[i].push_back(s[k]);
				if (i == (nRows-1)) down = false;
			}
			else
			{
				i--;
				zz[i].push_back(s[k]);
				if (i == 0) down = true;
			}
		}
		stringstream sstr;
		for (vector<vector<char>>::iterator ite = zz.begin(); ite!=zz.end(); ite++)
		{
			sstr << string(ite->begin(), ite->end());
		}
		sstr >> ret;
		return ret;
    }
};

void main()
{
	Solution ss;
	string res = ss.convert("AB", 1);
	cout << res;
}