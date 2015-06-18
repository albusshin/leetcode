class Solution {
public:
    vector<vector<string>> res;
    vector<int> queens; //queens[x] = y;
    int n;
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            queens.push_back(i);
            bt();
        }
        return res;
    }
    void bt() {
        if (queens.size() == n) {
            res.push_back(getboard());
            queens.pop_back();
            return;
        }
        int nowx = queens.size();
        for (int nowy = 0; nowy < n; nowy++) {
			bool able = true;
            for (int x = 0; x < queens.size(); x++) {
                int y = queens[x];
                if (nowx == x || nowy == y) {
					able = false;
					break;
				}
                int dx = abs(x - nowx), dy = abs(y - nowy);
                if (dx == dy) {
					able = false;
					break;
				}
            }
			if (able) {
				queens.push_back(nowy);
            	bt();
			}
        }
        queens.pop_back();
    }
    vector<string> getboard() {
        vector<string> ret;
        for (int x = 0; x < n; x++) {
            int y = queens[x];
            stringstream ss;
            string s = "";
            for (int i = 0; i < y; i++){
                ss << '.';
            }
            ss << 'Q';
            for (int i = y + 1; i < n; i++) {
                ss << '.';
            }
            ss >> s;
            ret.push_back(s);
        }
        return ret;
    }
};