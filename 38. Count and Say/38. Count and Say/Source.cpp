class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            stringstream ss;
            auto prev = s[0];
            int counter = 1;
            for (int j = 1; j < s.length(); j++) {
                char c = s[j];
                if (c == prev) {
                    counter++;
                }
                else {
                    ss << counter << prev;
                    counter = 1;
                    prev = c;
                }
            }
            ss << counter << prev;
            s = "";
            ss >> s;
        }
        return s;
    }
};