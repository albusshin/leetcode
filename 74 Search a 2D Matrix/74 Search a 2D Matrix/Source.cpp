class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        for (;;) {
            int midv = (up + down) / 2;
            vector<int> vi = matrix[midv];
            if (up > down) return false;
            if (vi[left] > target) down = midv - 1;
            else if (vi[right] < target) up = midv + 1;
            else {
                for (;;) {
                    if (left == right && vi[left] != target) return false;
                    if (left > right) return false;
                    int midh = (left + right) / 2;
                    if (vi[midh] == target) return true;
                    else if (vi[midh] > target) right = midh - 1;
                    else left = midh + 1;
                }
            }
        }
    }
};