class Solution {
	int n;
	int count;
    int ul;
    int ll;
    int rl;
    int dl;
    vector<vector<int>> ret;
public:
    vector<vector<int>> generateMatrix(int n) {
		if (!n) return ret;
		this->n = n;
		for (int i = 0; i < n; i++) {
			vector<int> v;
			for (int j = 0; j < n; j++) {
				v.push_back(0);
			}
			ret.push_back(v);
		}
        ul = -1;
        ll = -1;
        rl = n;
        dl = n;
		count = 1;
        while (count <= n * n) {
            r();
            d();
            l();
            u();
        }
        return ret; 
    }
	
    void r() {
        if (count > n * n) return;
        int sx = ul + 1, sy = ll + 1;
        ul++;
        for (; sy < rl; sy++) {
            ret[sx][sy] = count++;
        }
    }
    void d() {
        if (count > n * n) return;
        int sx = ul + 1, sy = rl - 1;
        rl--;
        for (; sx < dl; sx++) {
            ret[sx][sy] = count++;
        }
    }
    void l() {
        if (count > n * n) return;
        int sx = dl - 1, sy = rl - 1;
        dl--;
        for (; sy > ll; sy--) {
            ret[sx][sy] = count++;
        }
    }
    void u() {
        if (count > n * n) return;
        int sx = dl - 1, sy = ll + 1;
        ll++;
        for (; sx > ul; sx--) {
            ret[sx][sy] = count++;
        }
    }
};