class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationWith(k, n, 1);
    }
    vector<vector<int>> combinationWith(int k, int n, int startingWith) {
        vector<vector<int>> ret;
        if (k == 1) {
            if (n < startingWith || n > 9) return ret;
            else {
                vector<int> vi;
                vi.push_back(n);
                ret.push_back(vi);
                return ret;
            }
        }
        for (int i = startingWith; i <= 9; i++) {
            vector<vector<int>> vvi = combinationWith(k - 1, n - i, i + 1);
            for (auto virtd : vvi) {
                vector<int> vi(virtd);
                vi.insert(vi.begin(), i);
                ret.push_back(vi);
            }
        }
        return ret;
    }
};