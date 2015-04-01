#include <vector>
using namespace std;

class Solution {
	vector<vector<int>> dp;
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
		if (!dungeon.size()) return 0;
		int m = dungeon.size();
		int n = dungeon[0].size();
		dp.resize(m);
		for (int i = 0; i < m; i++) {
			dp[i].resize(n);
		}

		dp[m-1][n-1] = (1 - dungeon[m-1][n-1]) <= 0 ? 1 : (1 - dungeon[m-1][n-1]);
		for (int i = m - 2; i >= 0; i--) {
			//(i, n-1), last column
			int v = dp[i+1][n-1] - dungeon[i][n-1];
			dp[i][n-1] = v <= 0 ? 1 : v;
		}
		for (int j = n - 2; j >= 0; j--) {
			//(m-1, j), last row
			int v = dp[m-1][j+1] - dungeon[m-1][j];
			dp[m-1][j] = v <= 0 ? 1 : v;
		}
		for (int j = n - 2; j >= 0; j--) {
			//rest
			for (int i = m - 2; i >= 0; i--) {
				int vr = dp[i][j+1] - dungeon[i][j];
				int vd = dp[i+1][j] - dungeon[i][j];
				int v = min(vr, vd);
				dp[i][j] = v <= 0 ? 1 : v;
			}
		}
		return dp[0][0];
    }
};