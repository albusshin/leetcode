class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid.begin()->size();
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++) {
            vector<int> vi;
            for (int j = 0; j < n; j++) vi.push_back(0);
            dp.push_back(vi);
        }
        if (!obstacleGrid[m - 1][n - 1]) dp[m - 1][n - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 1) dp[i][n - 1] = 0;
            else dp[i][n - 1] = dp[i + 1][n - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            if (obstacleGrid[m - 1][i]) dp[m - 1][i] = 0;
            else dp[m - 1][i] = dp[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j]) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};