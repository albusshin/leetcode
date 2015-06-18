class Solution {
public:
    int res;
    vector<int> queens; //queens[x] = y;
    int n;
    int totalNQueens(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            queens.push_back(i);
            bt();
        }
        return res;
    }
    
    void bt() {
        if (queens.size() == n) {
            res++;
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
};