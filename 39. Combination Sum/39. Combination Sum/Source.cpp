class Solution {
    vector<vector<int>> vvi;
    vector<int> vi;
    vector<int> candidates;
    int target;
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
        this->target = target;
        this->candidates = candidates;
        bt(0);
        return vvi;
    }
    void bt(int pointer){
        while (pointer != candidates.size()){
            vi.push_back(candidates[pointer]);
            int sum = 0;
            for (auto i : vi) sum += i;
            if (sum > target) {
                vi.pop_back();
                return;
            }
            else if (sum == target) {
                vector<int> vipush(vi);
                vvi.push_back(vipush);
                vi.pop_back();
                return;
            }
            bt(pointer++);
			vi.pop_back();
        }
    }
};