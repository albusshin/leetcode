class Solution {
    public :
        int hammingWeight(uint32_t n) {
            int sum = 0;
            for (int i = 31; i >= 0; i++) {
                uint32_t nc = n;
                nc <<= i;
                nc >>= 31;
                sum += nc;
            }
            return sum;
        }
};
