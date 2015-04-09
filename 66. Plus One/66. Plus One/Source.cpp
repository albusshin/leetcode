class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool found = false;
        bool carry = false;
        for (auto rite = digits.rbegin(); rite != digits.rend(); ++rite) {
            if (*rite == 9) {
                *rite = 0;
                carry = true;
            }
            else {
                found = true;
                (*rite)++;
                break;
            }
        }
		if (!found && carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};