#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) return "";
        string prefix = strs[0];
		for (string str : strs) {
			for (int i = 0; i < prefix.length(); i++) {
				if (prefix[i] != str[i]) {
					prefix = prefix.substr(0, i);
				}
			}
		}
		return prefix;
    }
};