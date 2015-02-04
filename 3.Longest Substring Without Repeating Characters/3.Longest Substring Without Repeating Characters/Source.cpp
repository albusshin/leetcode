#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;
		unordered_map<char, int> hm;
		int i, j, max = 1;
		i=0;
		hm[s[i]] = 0;
		for (j=1; j!=s.size(); j++)
		{
			if (hm.find(s[j]) == hm.end())
			{
				hm[s[j]] = j;
			}
			else
			{
				max = max > hm.size() ? max : hm.size();
				int end = hm[s[j]];
				for (int k=i; k!=end; k++)
				{
					hm.erase(s[k]);
				}
				i = hm[s[j]] + 1;
				hm[s[j]] = j;
			}
			max = max > hm.size() ? max : hm.size();
		}
		return max;
    }
};

void main()
{
	Solution so;
	int res = so.lengthOfLongestSubstring("ggububgvfk");
	//string str = "abcda";
	//printf("%c\n,", str[str.size()]);
	printf("%d", res);
}