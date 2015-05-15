class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(),
            n = grid[0].size();
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++){
                v.push_back(0);
            }
            dp.push_back(v);
        }
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1][i] = grid[m - 1][i] + dp[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};