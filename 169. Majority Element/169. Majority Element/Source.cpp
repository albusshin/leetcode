class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> um;
        int halfsize = num.size() / 2;
        for (int i : num) {
            if (um.find(i) == um.end()) um[i] = 1;
            else um[i]++;
            if (um[i] > halfsize) return i;
        }
        return 0;
    }
};
