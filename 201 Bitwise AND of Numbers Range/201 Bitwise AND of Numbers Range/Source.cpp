class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int ret = 0;
        unsigned int um = m;
        unsigned int un = n;
        for (int i = 31; i >= 0; i--) {
            if ((um >> i << 31) ^ (un >> i << 31)) {
                break;
            }
            else {
                ret |= (um >> i << 31 >> (31 - i));
            }
        }
        return (int) ret;
    }
};