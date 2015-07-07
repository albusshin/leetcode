class Solution {
public:
    int countPrimes(int n) {
        bool* bitmap = new bool[n];
        int ret;
        memset(bitmap, 1, sizeof(bool) * (n));
        for (int i = 2; i < n; i++) {
            if (bitmap[i]) ret++;
            for (int j = 2; i * j < n; j++) bitmap[i * j] = false;
        }
        return ret;
    }
};