class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int y = i; y < n - i - 1; y++) {
                int tmp = matrix[i][y];
                matrix[i][y] = matrix[n-y-1][i];
                matrix[n-y-1][i] = matrix[n-i-1][n-y-1];
                matrix[n-i-1][n-y-1] = matrix[y][n-1-i];
                matrix[y][n-1-i] = tmp;
            }
        }
    }
};