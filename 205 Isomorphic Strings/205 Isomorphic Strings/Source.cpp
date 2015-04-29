class Solution {
public:
    map<char, vector<int>> m, m2;
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (m.find(c) == m.end()) {
                vector<int> pv;
                pv.push_back(i);
                m[c] = pv;
            }
            else{
                m[c].push_back(i);
            }
        }
        for (auto p : m) {
            m2.insert(make_pair(t[p.second[0]], p.second));
        }
        m.clear();
        for (int i = 0; i < t.length(); i++) {
            char c = t[i];
            if (m.find(c) == m.end()) {
                vector<int> pv;
                pv.push_back(i);
                m[c] = pv;
            }
            else{
                m[c].push_back(i);
            }
        }
        return m == m2;
    }
};