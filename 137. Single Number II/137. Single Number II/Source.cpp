class Solution {
public:
    int singleNumber(int A[], int n) {
        int bits[32];
        memset(bits, 0, sizeof(int) * 32);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                int aj = A[i] << (31 - j) >> 31;
                if (aj) bits[j]++;
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            ret += (bits[i] % 3) << i;
        }
        return ret;
    }
};