class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        int **dp = new int* [m];
        for (int i = 0; i < m; i++) dp[i] = new int[n];
        int ret = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                char c = matrix[i][j];
                if (c == '0') dp[i][j] = 0;
                else if (i < m - 1 && j < n - 1)
                    dp[i][j] = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1])) + 1;
                else dp[i][j] = 1;
                ret = max(dp[i][j], ret);
            }
        }
        return ret * ret;
    }
};