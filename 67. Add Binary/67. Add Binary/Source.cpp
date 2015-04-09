class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        stringstream ss;
        string ret;
        auto rite = a.rbegin(),
            rjte = b.rbegin();
        while (rite != a.rend() || rjte != b.rend()) {
            char ci, cj;
            if (rite == a.rend()) {
                ci = '0';
                cj = *rjte;
            }
            else if (rjte == b.rend()) {
                ci = *rite;
                cj = '0';
            }
            else {
                ci = *rite;
                cj = *rjte;
            }
            if (ci == '1' && cj == '1') {
                if (carry) ss << 1;
                else {
                    ss << 0;
                    carry = true;
                }
            }
            else if ((ci == '0' && cj == '1') || (ci == '1' && cj == '0')) {
                if (carry) ss << 0;
                else ss << 1;
            }
            else { // two 0's
                if (carry) {
                    ss << 1;
                    carry = false;
                }
                else ss << 0;
            }
            if (rite != a.rend()) ++rite;
            if (rjte != b.rend()) ++ rjte;
        }
        if (carry) ss << 1;
        ret.clear();
        ss >> ret;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};