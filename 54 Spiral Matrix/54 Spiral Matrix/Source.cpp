class Solution {
    int m;
    int n;
    int ul;
    int ll;
    int rl;
    int dl;
    vector<vector<int>> matrix;
    vector<int> ret;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        if (matrix.empty()) return ret;
        m = matrix.size();
        n = matrix[0].size();
        ul = -1;
        ll = -1;
        rl = n;
        dl = m;
        while (ret.size() < m * n) {
            r();
            d();
            l();
            u();
        }
        return ret;
    }
    void r() {
        if (ret.size() >= m * n) return;
        int sx = ul + 1, sy = ll + 1;
        ul++;
        for (; sy < rl; sy++) {
            ret.push_back(matrix[sx][sy]);
        }
    }
    void d() {
        if (ret.size() >= m * n) return;
        int sx = ul + 1, sy = rl - 1;
        rl--;
        for (; sx < dl; sx++) {
            ret.push_back(matrix[sx][sy]);
        }
    }
    void l() {
        if (ret.size() >= m * n) return;
        int sx = dl - 1, sy = rl - 1;
        dl--;
        for (; sy > ll; sy--) {
            ret.push_back(matrix[sx][sy]);
        }
    }
    void u() {
        if (ret.size() >= m * n) return;
        int sx = dl - 1, sy = ll + 1;
        ll++;
        for (; sx > ul; sx--) {
            ret.push_back(matrix[sx][sy]);
        }
    }
};