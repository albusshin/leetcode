class Solution {
    int dp[1000];
public:
    Solution() {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < 1000; i++) dp[i] = -1;
    }
    int numTrees(int n) {
        if (dp[n] != -1) return dp[n];
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += numTrees(i - 1) * numTrees(n - i);
        }
        return dp[n] = count;
    }
};