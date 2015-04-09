class Solution {
public:
    int dp[1000];
    Solution() {
        for (int i = 0; i < 1000; i++) dp[i] = 0;
    }
    int climbStairs(int n) {
        if (n == 0) return dp[0] = 1;
        if (n == 1) return dp[1] = 1;
        if (dp[n] != 0) return dp[n];
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};