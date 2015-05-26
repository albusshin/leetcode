class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            if (s.find(i) == s.end()) s.insert(i);
            else return true;
        }
        return false;
    }
};
