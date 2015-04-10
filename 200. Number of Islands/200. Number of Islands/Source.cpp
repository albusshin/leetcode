class Solution {
    vector<vector<bool>> visited;
    int counter;
    int m, n;
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        visited.resize(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i].push_back(false); 
            }
        }
        counter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(grid, i, j)) counter++;
            }
        }
        return counter;
    }
    bool dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0) return false;
        if (i >= m || j >= n) return false;
        if (visited[i][j]) return false;
        visited[i][j] = true;
        if (grid[i][j] == '1') {
            dfs(grid, i+1, j);
            dfs(grid, i, j+1);
            dfs(grid, i-1, j);
            dfs(grid, i, j-1);
            return true;
        } else return false;
    }
};