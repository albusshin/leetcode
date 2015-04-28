class Solution {
public:
    vector<int> memo;
    bool isHappy(int n) {
		do {
            int tmp = 0;
            do {
                int digit = n % 10;
                tmp += digit * digit;
            } while (n /= 10);
            n = tmp;
            memo.push_back(n);
            if (n == 1) return true;
        }
        while (find(memo.rbegin() + 1, memo.rend(), n) == memo.rend());
        return false;
    }
};