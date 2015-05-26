class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vi;
		for (int i = 1; i <= n; i++) vi.push_back(i);
		return combine(vi, k);
    }
    vector<vector<int>> combine(vector<int> v, int k) {
        vector<vector<int>> vvi;
		int n = v.size();
        if (k == 1) {
            for (int i : v) {
                vector<int> tmpv;
                tmpv.push_back(i);
                vvi.push_back(tmpv);
            }
            return vvi;
        }
        else {
            for (int i = 0; i <= n - k; i++) {
                int chosen = v[i];
                auto start = v.begin() + i + 1;
                vector<int> tmpv(start, v.end());
                vector<vector<int>> subvvi = combine(tmpv, k - 1);
                for (vector<int> subv : subvvi) {
                    subv.insert(subv.begin(), chosen);
                    vvi.push_back(subv);
                }
            }
            return vvi;
        }
    }
};