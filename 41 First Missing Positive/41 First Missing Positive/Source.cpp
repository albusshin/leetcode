class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 1;
        vector<int> pi;
        pi.push_back(1);
        for (int i = 1; i < n+2; i++) {
            pi.push_back(0);
        }
        for (int i : nums) {
            if (i <= 0) continue;
            else if (i > n ) continue;
            pi[i] = 1;
        }
        for (int i = 1; i <= n + 1; i++) {
            if (!pi[i]) {
				return i;
			}
        }
        return 0;
    }
};