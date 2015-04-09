class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int count = 0;
        bool lastcount = false;
        for (int i = 0; s[i]; i++) {
            if (isspace(s[i])) {
                lastcount = true;
            }
            else if (lastcount) {
                count = 1;
                lastcount = false;
            }
            else {
                count++;
                lastcount = false;
            }
        }
        return count;
    }
};