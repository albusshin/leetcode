#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string getLPSeparatedBy(string s, int from) {
        int left = from - 1;
        int right = from + 1;
        int max = 1;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            max += 2;
        }
		left++; right--;
        string ret = s.substr(left, right - left + 1);
        left = from;
        right = from + 1;
        int secondMax = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            secondMax += 2;
        }
		left++; right--;
        if (secondMax > max) 
			ret = s.substr(left, right - left + 1);
		cout << max << " " << secondMax << " " << ret << endl;
        return ret;
        
    }
    string longestPalindrome(string s) {
        string ret = "";
        for (int i = 0; i < s.length(); i++) {
            string tmp = getLPSeparatedBy(s, i);
            if (ret.length() < tmp.length()) ret = tmp;
        }
        return ret;
    }
};

void main() {
	Solution sol;
	string s = sol.longestPalindrome("bb");
	cout << s << endl;
}