class Solution {
public:
    string convertToTitle(int n) {
        stringstream ss;
        while (n != 0) {
            n--;
            int bit = n % 26;
            ss << (char)(bit + 'A');
            n /= 26;
        }
        string str;
        ss >> str;
        str = string(str.rbegin(), str.rend());
        return str;
    }
};
