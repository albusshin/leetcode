class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vvi;
        if (nums.empty()) return vvi;
        if (nums.size() == 1) {
            vector<int> vi(nums);
            vvi.push_back(vi);
            return vvi;
        }
        else if (nums.size() == 2) {
            vector<int> vi1(nums);
            vvi.push_back(vi1);
            vector<int> vi2;
            vi2.push_back(nums[1]);
            vi2.push_back(nums[0]);
            vvi.push_back(vi2);
        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                vector<int> tmpnums(nums);
                tmpnums.erase(tmpnums.begin() + i);
                int tmp = nums[i];
                vector<vector<int>> subvv = permute(tmpnums);
                for (vector<int> vi : subvv) {
                    vi.insert(vi.begin(), tmp);
                    vvi.push_back(vi);
                }
            }
            return vvi;
        }
    }
};