class Solution {
    int prev, nowStart, now;
    vector<string> ret;
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return ret;
        prev = nums[0];
        nowStart = prev;
        now = prev;
        for (int i = 1; i < nums.size(); i++) {
            now = nums[i];
            if (now != prev + 1) close();
            prev = now;
        }
        close();
        return ret;
    }
    void close() {
        stringstream ss;
        string s;
        if (nowStart == prev) {
            ss << prev;
            ss >> s;
        }
        else {
            ss << nowStart << "->" << prev;
            ss >> s;
        }
        ret.push_back(s);
        nowStart = now;
    }
};