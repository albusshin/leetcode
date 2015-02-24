#include <cmath>

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int pass, ret;
        pass = ret = A[0];
        for (int i = 1; i < n; i++) {
            pass = max(A[i], A[i] + pass);
            ret = max(pass, ret);
        }
        return ret;
    }
};