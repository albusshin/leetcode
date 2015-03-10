class Solution {
public:
    bool equal(char l, char r) {
        if (l == r) return true;
        if (l >= 'A' && l <= 'Z') l -= ('A' - 'a');
        if (r >= 'A' && r <= 'Z') r -= ('A' - 'a');
        if (l == r) return true;
        return false;
    }
    bool isPalindrome(string s) {
        auto ite = s.begin();
        auto rite = s.rbegin();
        for (; ite != s.end(); ite++, rite++) {
            while (ite != s.end() && !((*ite >= 'A' && *ite <= 'Z') || (*ite >= 'a' && *ite <= 'z') || (*ite >= '0' && *ite <= '9'))) ++ite;
            while (rite != s.rend() && !((*rite >= 'A' && *rite <= 'Z') || (*rite >= 'a' && *rite <= 'z') || (*rite >= '0' && *rite <= '9'))) ++rite;
            if (ite == s.end() && rite == s.rend()) return true;
            if (!equal(*ite, *rite)) return false;
        }
        return true;
    }
};
