class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, set<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (mp.find(n) == mp.end()) {
                set<int> st;
                st.insert(i);
                mp[n] = st;
            }
            else {
                mp[n].insert(i);
            }
        }
        for (auto ite = mp.begin(); ite != mp.end(); ++ite) {
            set<int> theSet;
            for (auto jte = ite; jte != mp.end() && abs((long long)jte->first - (long long)ite->first) <= t; ++jte) {
                set<int> st = jte->second;
                for (int i : st) theSet.insert(i);
            }
            int prev = -k - 1;
            for (int i : theSet) {
                if (i - prev <= k) return true;
                prev = i;
            }
        }
        return false;
    }
};