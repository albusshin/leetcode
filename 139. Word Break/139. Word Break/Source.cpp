class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_map<string, bool> dp;
        return recur(s, dict, dp);
    }
    bool recur(string s, unordered_set<string> &dict, unordered_map<string, bool> &dp) {
        if (s.empty()) return true;
        if (dp.find(s) != dp.end()) return dp[s];
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            string postfix = s.substr(i);
            if (dict.find(prefix) != dict.end() && recur(postfix, dict, dp)) return dp[s] = true;
        }
        return dp[s] = false;
    }
};