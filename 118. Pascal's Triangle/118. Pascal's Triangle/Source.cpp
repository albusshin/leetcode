class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        if (!numRows) return ret;
        vector<int> one;
        one.push_back(1);
        ret.push_back(one);
        if (numRows == 1) return ret;
        vector<int> two;
        two.push_back(1);
        two.push_back(1);
        ret.push_back(two);
        if (numRows == 2) return ret;
        for (int i = 3; i <= numRows; i++) { //i == size
            vector<int> vi;
            vi.push_back(1);
            for (int j = 1; j <= i - 2; j++) {
                vector<int>& prev = ret[i-2];
                vi.push_back(prev[j - 1] + prev[j]);
            }
            vi.push_back(1);
            ret.push_back(vi);
        }
        return ret;
    }
};
