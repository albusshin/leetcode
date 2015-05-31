class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, set<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (mp.find(n) == mp.end()) {
                set<int> st;
                st.insert(i);
                mp[n] = st;
            }
            else mp[n].insert(i);
        }
        for (auto pr : mp) {
            set<int> st = pr.second;
            int prev = -k - 1;
            for (auto i : st) {
                if (i - prev <= k) return true;
                prev = i;
            }
        }
        return false;
    }
};