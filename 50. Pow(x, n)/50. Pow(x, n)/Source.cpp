class Solution {
    double memopos[32], memoneg[32];
public:
    double pow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        memopos[0] = x;
        memoneg[0] = 1 / x;
        for (int i = 1; i < 32; i++){
            memopos[i] = memopos[i-1] * memopos[i-1];
            memoneg[i] = memoneg[i-1] * memoneg[i-1];
        }
        int pow2 = 0;
        double ret = 1;
        double *memo = memopos;
        if (n < 0) {
            memo = memoneg;
            n = -n;
        }
        for (int i = 0; i < 32; i++) {
            if (n << (31 - i) >> 31) ret *= memo[i];
        }
        return ret;
    }
};